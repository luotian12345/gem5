./build/ARM/gem5.opt \
    --debug-flags=AcceleratorONE,AcceleratorTWO,AcceleratorTHREE,AddrRanges,TrafficGen,ReceivePacket \
    configs/example/fs_test.py \
        --kernel=/home/luot/2022/os/linux/vmlinux \
        --disk=fs-image/linaro-minimal-aarch64.img \
        --cpu-type=O3CPU \
        --caches