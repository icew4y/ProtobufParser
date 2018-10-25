

set(command "C:/Program Files/CMake/bin/cmake.exe;-CD:/3rd/protobuf/out/examples/tmp/examples-cache-Debug.cmake;-GVisual Studio 15 2017;-DCMAKE_GENERATOR_INSTANCE:INTERNAL=C:/Program Files (x86)/Microsoft Visual Studio/2017/Professional;D:/3rd/protobuf/examples")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "D:/3rd/protobuf/out/examples/logs/examples-configure-out.log"
  ERROR_FILE "D:/3rd/protobuf/out/examples/logs/examples-configure-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  D:/3rd/protobuf/out/examples/logs/examples-configure-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "examples configure command succeeded.  See also D:/3rd/protobuf/out/examples/logs/examples-configure-*.log")
  message(STATUS "${msg}")
endif()
