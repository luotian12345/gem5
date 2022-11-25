./build/ARM/gem5.opt \
    --debug-flags=AcceleratorONE,AcceleratorTWO,AcceleratorTHREE,AddrRanges,ReceivePacket \
    configs/example/fs_test.py \
        --kernel=/home/luot/2022/os/linux/vmlinux \
        --disk=fs-image/linaro-minimal-aarch64.img \
        --chi-config=./configs/example/noc_config/2x2.py \
        --topology=Ring \
        --caches \
        --num-cpus=4 \
        --cpu-type=O3CPU \
        --num-dirs=2 \
        --num-l3caches=2 \
        --network=garnet \
        --router-latency=2 \
        --ruby
#--script=./configs/example/test.rcS

#--bootloader=/home/luot/gem5-21.1.0.2/fs-image/binaries/boot.arm64 \