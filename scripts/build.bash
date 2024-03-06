#!/bin/bash

mos build --verbose --local --platform ubuntu && unzip ./build/fw.zip -d ./build/fs && mv ./build/fs/zmos-1.0/* ./build/fs && rm -r ./build/fs/zmos-1.0 && chmod +x ./build/fs/zmos.elf
