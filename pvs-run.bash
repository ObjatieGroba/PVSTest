mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=On
pvs-studio-analyzer analyze -o pvs.log
plog-converter -a GA:1,2 -t html pvs.log -o pvs.html
plog-converter -a GA:1,2 -t tasklist -o pvs.tasks pvs.log
