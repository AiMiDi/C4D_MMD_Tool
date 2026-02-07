#!/bin/sh

if type -p ccache >/dev/null 2>&1; then
  export CCACHE_BASEDIR=${PWD}/../../../
  export CCACHE_CPP2=1
  export CCACHE_SLOPPINESS=time_macros,clang_index_store,locale,include_file_mtime,include_file_ctime
  export CCACHE_COMMENTS=
  exec ccache clang "$@"
else
  exec clang "$@"
fi
