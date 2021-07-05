TSAN_OPTIONS="second_deadlock_stack=1 $TSAN_OPTIONS"
TSAN_SUPPRESSIONS="/etc/tbricks/sanitizers/tsan_suppressions"
[ -r "$TSAN_SUPPRESSIONS" ] && TSAN_OPTIONS="$TSAN_OPTIONS suppressions=$TSAN_SUPPRESSIONS"
export TSAN_OPTIONS
