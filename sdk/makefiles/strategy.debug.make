###############################################################################
#  Tbricks Strategy SDK.
#
#  Copyright (c) 2006-2011 Tbricks AB.
#
#  Build wrapper for SDK based strategies, compiler options section.
#
###############################################################################

##### Compiler options.
CFLAGS+=-isystem$(SDK)/include64
CFLAGS+=$(addprefix -I,$(HEADERS))
CFLAGS+=-DLINUX -DLINUX64 -DU_USING_ICU_NAMESPACE=0 -DLUA_LIB=\"tbricks_lua\" -DLUAJIT_LIB=\"luajit\" -DTB_USE_RCU -DURCU_INLINE_SMALL_FUNCTIONS -DDEBUG_RCU -DFMT_SHARED -D_POSIX_PTHREAD_SEMANTICS
CFLAGS+=-fPIC
CFLAGS+=-D_GNU_SOURCE -m64 --gcc-toolchain=/opt/gcc-8.2.0 -fuse-ld=gold-2.25 -pipe -fno-omit-frame-pointer -ffast-math -fno-finite-math-only -pthread -march=core2 -mtune=corei7 -g -Qunused-arguments -fgnu89-inline -fvisibility=hidden -Wstrict-prototypes -Wmissing-prototypes -Wall -Wextra -Wshadow -Wpointer-arith -Werror=self-assign -Wno-unused-function -Wno-gnu-empty-initializer -Wno-unused-parameter -Wno-ignored-qualifiers -Wno-mismatched-tags -Wno-unused-local-typedef -Wno-parentheses-equality -Wno-unused-private-field -Wno-missing-field-initializers -Wno-missing-braces -Wunreachable-code -Werror=return-stack-address -pedantic -Werror=return-type
CFLAGS.mkdep+=-M -MP
CFLAGS.mkdep+=$(CFLAGS)
CXXFLAGS+=-isystem$(SDK)/include64
CXXFLAGS+=$(addprefix -I,$(HEADERS))
CXXFLAGS+=-DLINUX -DLINUX64 -DU_USING_ICU_NAMESPACE=0 -DLUA_LIB=\"tbricks_lua\" -DLUAJIT_LIB=\"luajit\" -DTB_USE_RCU -DURCU_INLINE_SMALL_FUNCTIONS -DDEBUG_RCU -DFMT_SHARED -D_POSIX_PTHREAD_SEMANTICS
CXXFLAGS+=-fPIC
CXXFLAGS+=-D_GNU_SOURCE -D_GLIBCXX_USE_CXX11_ABI=0 -m64 --gcc-toolchain=/opt/gcc-8.2.0 -fuse-ld=gold-2.25 -std=gnu++17 -D_GLIBCXX_DEPRECATED= -pipe -fno-omit-frame-pointer -ffast-math -fno-finite-math-only -pthread -march=core2 -mtune=corei7 -g -Qunused-arguments -fnon-call-exceptions -fvisibility=hidden -fvisibility-inlines-hidden -Wall -Wextra -Wshadow -Wpointer-arith -Werror=self-assign -Wno-unused-function -Wno-gnu-empty-initializer -Wno-unused-parameter -Wno-ignored-qualifiers -Wno-mismatched-tags -Wno-unused-local-typedef -Wno-parentheses-equality -Wno-unused-private-field -Wno-missing-field-initializers -Wno-missing-braces -Wunreachable-code -Werror=return-stack-address -Werror=return-type -Werror=overloaded-virtual
ifeq ($(DISABLE_CXX11),YES)
CXXFLAGS := $(filter-out -std=c++1%,$(filter-out -std=gnu++1%,$(CXXFLAGS)))
endif
CXXFLAGS.mkdep+=-M -MP
CXXFLAGS.mkdep+=$(CXXFLAGS)
LDFLAGS.library-dynamic+=-shared -fuse-ld=gold-2.25
LDFLAGS.library-dynamic+=-L$(SDK)/platform/lib64
LDFLAGS.library-dynamic+=-ltbricks_strategy_2.14.6.v255
ARFLAGS=rusc
LIBPFX=lib
LIBEXT=.a
SOLIBEXT=.so
