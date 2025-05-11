sdcc.exe --out-fmt-elf -mstm8  --debug    -Iinc -Iinc -I"C:\Program Files (x86)\SDCC\include" -c src\adc.c -o obj\Debug\src\adc.rel
sdcc.exe --out-fmt-elf -mstm8  --debug    -Iinc -Iinc -I"C:\Program Files (x86)\SDCC\include" -c src\main.c -o obj\Debug\src\main.rel
sdcc.exe --out-fmt-elf -mstm8  --debug    -Iinc -Iinc -I"C:\Program Files (x86)\SDCC\include" -c src\timer.c -o obj\Debug\src\timer.rel
sdcc.exe --out-fmt-elf -mstm8  --debug    -Iinc -Iinc -I"C:\Program Files (x86)\SDCC\include" -c src\uart.c -o obj\Debug\src\uart.rel
sdcc.exe -L"C:\Program Files (x86)\SDCC\lib" -L"C:\Program Files (x86)\SDCC\lib" -o "bin\Debug\STM8S003F3_demo.ihx" --out-fmt-elf -mstm8  --debug  obj\Debug\src\adc.rel obj\Debug\src\main.rel obj\Debug\src\timer.rel obj\Debug\src\uart.rel
