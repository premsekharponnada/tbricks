#!/bin/sh

DTRACE=${DTRACE:-/usr/sbin/dtrace}

# path to dtrace scripts directory, relative to build root dir (MK_BUILD_ROOT in Build System parlance)
DTRACE_SCRIPTS_ROOT=../src/scripts/dtrace

VALGRIND=${VALGRIND:-/usr/bin/valgrind}
VALGRIND_PARAMS=${VALGRIND_PARAMS:-"--soname-synonyms=somalloc=*jemalloc*,somalloc=libtbricks_stlport4-alloc.so --tool=memcheck --leak-check=full --show-reachable=yes --track-fds=yes --time-stamp=yes --num-callers=20"}

ONLOAD=${ONLOAD:-/usr/bin/onload}

LIBSTD=""

#
# Global definitions - OS, tbricks binary directory, program name.
#
os=`uname -s`
eval 'bindir=`cd "'`dirname "$0"`'" &&pwd`'
prog=`basename "$0"`
while [ "$bindir" != "/" ]; do
    dir=`basename $bindir`
    if [ "$dir" = "bin" ]; then break; fi
    prog=$dir/$prog
    bindir=`dirname $bindir`
done

#
# start_process <rootdir> <bitness suffix> <executable name> <... arguments ...>
#
# sets LD_LIBRARY_PATH, DYLD_LIBRARY_PATH and exec()'s
#
# (note that the order of <bitness suffix> and <executable name> is different than in
#  other functions with similar parameters)
#
start_process()
{
    _rootdir="$1"; shift
    _sfx="$1"; shift
    _prog="$1"; shift

    _lib=$LIBSTD$_rootdir/platform/lib$_sfx
    _name=`basename $prog`

    if [ x"$os" = xDarwin ]; then
        [ -z "$DYLD_LIBRARY_PATH" ] && DYLD_LIBRARY_PATH=$_lib ||
            DYLD_LIBRARY_PATH=$_lib:$DYLD_LIBRARY_PATH
        DYLD_BIND_AT_LAUNCH=1
        export DYLD_BIND_AT_LAUNCH
        export DYLD_LIBRARY_PATH
    else
        [ -z "$LD_LIBRARY_PATH" ] && LD_LIBRARY_PATH=$_lib ||
            LD_LIBRARY_PATH=$_lib:$LD_LIBRARY_PATH

        if [ x"$os" = xSunOS ]; then
            LD_NOLAZYLOAD=1
            export LD_NOLAZYLOAD
        fi

        LD_BIND_NOW=1
        export LD_BIND_NOW
        export LD_LIBRARY_PATH
    fi

    _libstlport4_alloc="$_lib/libtbricks_stlport4-alloc.so"
    _libjemalloc="$_lib/libjemalloc.so.2"
    _libjemalloc_debug="$_lib/../../debug/platform/lib$_sfx/libjemalloc.so.2"
    _libmath="$_lib/libtbricks_math.so"

    if [ "$os" = "Linux" ]; then
        if [ x"$TB_JEMALLOC_DEBUG" = "x1" -a -x "$_libjemalloc_debug" ]; then
            ADDITIONAL_LD_PRELOAD="$_libjemalloc_debug $ADDITIONAL_LD_PRELOAD"
        elif [ -x "$_libjemalloc" ]; then
            ADDITIONAL_LD_PRELOAD="$_libjemalloc $ADDITIONAL_LD_PRELOAD"
        fi

        if [ -z "$MALLOC_CONF" ]; then
            MALLOC_CONF="prof:true,prof_active:false,prof_prefix:,lg_prof_sample:20,prof_accum:true"
            export MALLOC_CONF
        fi

    fi

    if [ -z "$TB_RELEASE_ROOT" ]; then
        eval 'TB_RELEASE_ROOT=$(cd "'$_rootdir'" && pwd)'
        export TB_RELEASE_ROOT
    fi

    # load common scripts
    for f in $_lib/scripts_common/*.sh; do
        [ -f $f ] && . $f
    done

    if [ "$os" = "Linux" ] && [ "$sanitizer" != "yes" ]; then
        if [ -x "$_libmath" ]; then
            ADDITIONAL_LD_PRELOAD="$_libmath $ADDITIONAL_LD_PRELOAD"
        fi
        if [ -x "$_libstlport4_alloc" ]; then
            ADDITIONAL_LD_PRELOAD="$_libstlport4_alloc $ADDITIONAL_LD_PRELOAD"
        fi
    fi

    if [ "$os" = "Linux" ] && [ "$preload_asan" = "yes" ]; then
        if [ -x "$ASAN_RT_PATH" ]; then
            ADDITIONAL_LD_PRELOAD="$ASAN_RT_PATH $ADDITIONAL_LD_PRELOAD"
        fi
    fi

    LD_PRELOAD="$LD_PRELOAD $ADDITIONAL_LD_PRELOAD"
    export LD_PRELOAD

    # load server script plugins
    [ -f $_lib/scripts/$_name ] &&
        . $_lib/scripts/$_name

    exec "$_prog" "$@"
}

#
# start <rootdir> <prog name> <bitness suffix> <... arguments ...>
#
start()
{
    _rootdir="$1"; shift
    _name="$1"; shift
    _sfx="$1"; shift

    _prog=$_rootdir/platform/bin$_sfx/$_name

    if [ -x "$_prog" ]; then
        # TB-80367: two-step launch under onload to avoid unexpected LD_PRELOAD impact on thirdparty software
        if [ -n "$TB_ONLOAD_PROFILE" ] && [ -x "$ONLOAD" ]; then
            TB_ONLOAD_PROFILE_LOCAL=$TB_ONLOAD_PROFILE
            unset TB_ONLOAD_PROFILE
            exec "$ONLOAD" --profile="$TB_ONLOAD_PROFILE_LOCAL" "$bindir/$prog" "$@"
        else
            start_process "$_rootdir" "$_sfx" "$_prog" "$@"
        fi
    fi
}

#
# ldd <rootdir> <prog name> <bitness suffix> <... arguments ...>
#
ldd()
{
    _rootdir="$1"; shift
    _name="$1"; shift
    _sfx="$1"; shift

    _prog=$_rootdir/platform/bin$_sfx/$_name

    if [ -x "$_prog" ]; then
        start_process "$_rootdir" "$_sfx" ldd "$_prog" "$@"
    fi
}

#
# debug <debugger> <debugger arguments> <rootdir> <prog name> <bitness suffix> <... arguments ...>
#
debug()
{
    _dbg="$1"; shift
    _dbg_arg="$1"; shift
    _rootdir="$1"; shift
    _name="$1"; shift
    _sfx="$1"; shift

    _prog=$_rootdir/platform/bin$_sfx/$_name

    LIBSTD=`/usr/bin/env ldd $_prog | sed -nE 's/libstdc++.* => (.*) \(.*\)/\1/p' | xargs echo | xargs dirname`
    LIBSTD+=":"

    if [ "$_dbg" == "lldb" ]; then
        eval "set -- $_dbg_arg "$_prog" -- "$@""
    else
        eval "set -- $_dbg_arg "$_prog" "$@""
    fi

    if [ -x "$_prog" ]; then
        start_process "$_rootdir" "$_sfx" "$_dbg" "$@"
    fi
}

head_arg()
{
    echo "$1"
}

tail_arg()
{
    shift
    echo "$@"
}

quote_args()
{
    res=""

    for arg do
        if echo "$arg" | grep " " >/dev/null 2>&1; then
            res="$res \"$arg\""
        else
            res="$res $arg"
        fi
        shift
    done

    echo "$res"
}

#
# dtrace <dtrace params> <rootdir> <prog name> <bitness suffix> <... arguments ...>
#
dtrace()
{
    if [ "$os" != "SunOS" ]; then
        echo "DTrace is available only on Solaris"
        exit 1
    fi

    _dtrace_args="$1"; shift
    _rootdir="$1"; shift
    _name="$1"; shift
    _sfx="$1"; shift

    _prog=$_rootdir/platform/bin$_sfx/$_name

    if [ -x "$_prog" ]; then
        dtrace_script_name=`head_arg $_dtrace_args`
        dtrace_script_args=`tail_arg $_dtrace_args`

        dtrace_script="$dtrace_script_name"

        if [ ! -f "$dtrace_script" ]; then
            dtrace_script="$_rootdir/$DTRACE_SCRIPTS_ROOT/$dtrace_script_name"
        fi

        if [ ! -f "$dtrace_script" ]; then
            echo "Cannot find dtrace script '$dtrace_script'"
            exit 1
        fi

        cmd_line=`quote_args "$@"`

        cmd_str="$_prog $cmd_line"

        start_process "$_rootdir" "$_sfx" "$DTRACE" -s "$dtrace_script" $dtrace_script_args -c "$cmd_str"
    fi
}

#
# valgrind <valgrind params> <rootdir> <prog name> <bitness suffix> <... arguments ...>
#
valgrind()
{
    if [ "$os" != "Linux" ]; then
        echo "Valgrind is available only on Linux"
        exit 1
    fi

    _rootdir="$1"; shift
    _name="$1"; shift
    _sfx="$1"; shift

    _prog=$_rootdir/platform/bin$_sfx/$_name

    _valgrind_params="$VALGRIND_PARAMS --log-file=${_rootdir}/bin/${_name}-%p.vglog"

    if [ -x "$_prog" ]; then
        start_process "$_rootdir" "$_sfx" "$VALGRIND" $_valgrind_params "$_prog" "$@"
    fi
}
#
# daemon <rootdir> <prog name> <bitness suffix> <... arguments ...>
#
daemon()
{
    _rootdir="$1"; shift
    _name="$1"; shift
    _sfx="$1"; shift

    _prog=$_rootdir/platform/bin$_sfx/$_name

    if [ -x "$_prog" ]; then
        start_process "$_rootdir" "$_sfx" "$_rootdir/platform/bin$_sfx/tbdaemon" "$_prog" "$@"
    fi
}

#
# leaks <rootdir> <prog name> <bitness suffix> <... arguments ...>
#
leaks()
{
    _rootdir="$1"; shift
    _name="$1"; shift
    _sfx="$1"; shift

    _prog=$_rootdir/platform/bin$_sfx/$_name

    if [ -x "$_prog" ]; then
        MallocStackLogging=1
        export MallocStackLogging
        start_process "$_rootdir" "$_sfx" "$_prog" "$@"
        # start_process() exec()'s so no need to unexport MallocStackLogging
    fi
}

#
# asan <rootdir> <prog name> <bitness suffix> <... arguments ...>
#
asan()
{
    _rootdir="$1"; shift
    _name="$1"; shift
    _sfx="$1"; shift

    _prog=$_rootdir/platform/bin$_sfx/$_name

    if [ -x "$_prog" ]; then
        preload_asan=yes
        start_process "$_rootdir" "$_sfx" "$_prog" "$@"
    fi
}

main()
{
    case "$1" in
    debug)
        shift;
        case "$os" in
        SunOS)
            PATH=/opt/SUNWspro/bin:$PATH
            export PATH
            _dbg=dbx
            ;;
        *)
            _dbg_arg="-iex \"set auto-load safe-path /\" -q --args"
            _dbg="gdb"
            ;;
        esac

        debug "$_dbg" "$_dbg_arg" "$bindir/.." "$prog" "64" "$@"
        debug "$_dbg" "$_dbg_arg" "$bindir/.." "$prog" "32" "$@"
        debug "$_dbg" "$_dbg_arg" "$bindir/.." "$prog" "" "$@"
        ;;
    gdb)
        shift;
        _dbg_arg="-iex \"set auto-load safe-path /\" -q --args"
        _dbg="gdb"
        debug "$_dbg" "$_dbg_arg" "$bindir/.." "$prog" "64" "$@"
        debug "$_dbg" "$_dbg_arg" "$bindir/.." "$prog" "32" "$@"
        debug "$_dbg" "$_dbg_arg" "$bindir/.." "$prog" "" "$@"
        ;;
    lldb)
        shift;
        _dbg="lldb"
        debug "$_dbg" "-f" "$bindir/.." "$prog" "64" "$@"
        debug "$_dbg" "-f" "$bindir/.." "$prog" "32" "$@"
        debug "$_dbg" "-f" "$bindir/.." "$prog" "" "$@"
        ;;
    ldd)
        shift;
        ldd "$bindir/.." "$prog" "64" "$@"
        ldd "$bindir/.." "$prog" "32" "$@"
        ldd "$bindir/.." "$prog" "" "$@"
        ;;
    dtrace)
        shift;
        dtrace_args="$1"; shift
        dtrace "$dtrace_args" "$bindir/.." "$prog" "64" "$@"
        dtrace "$dtrace_args" "$bindir/.." "$prog" "32" "$@"
        dtrace "$dtrace_args" "$bindir/.." "$prog" "" "$@"
        ;;
    daemon)
        shift;
        daemon "$bindir/.." "$prog" "64" "$@"
        daemon "$bindir/.." "$prog" "32" "$@"
        daemon "$bindir/.." "$prog" "" "$@"
        ;;
    leaks)
        shift;
        leaks "$bindir/.." "$prog" "64" "$@"
        leaks "$bindir/.." "$prog" "32" "$@"
        leaks "$bindir/.." "$prog" "" "$@"
        ;;
    valgrind)
        shift
        valgrind "$bindir/.." "$prog" "64" "$@"
        valgrind "$bindir/.." "$prog" "32" "$@"
        valgrind "$bindir/.." "$prog" "" "$@"
        ;;
    asan)
        shift
        asan "$bindir/.." "$prog" "64" "$@"
        asan "$bindir/.." "$prog" "32" "$@"
        asan "$bindir/.." "$prog" "" "$@"
        ;;
    *)
        start "$bindir/.." "$prog" "64" "$@"
        start "$bindir/.." "$prog" "32" "$@"
        start "$bindir/.." "$prog" "" "$@"
        ;;
    esac
}

main "$@"
