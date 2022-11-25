./build/ARM/gem5.opt \
    --debug-flags=AcceleratorONE,AcceleratorTWO,AddrRanges,ExecKernel \
    configs/example/arm/ruby_fs_test.py \
        --kernel=fs-image/vmlinux \
        --disk=fs-image/linaro-minimal-aarch64.img \
        --chi-config=./configs/example/noc_config/2x2.py \
        --topology=Ring \
        --num-cpus=4 \
        --cpu=o3 \
        --num-dirs=2 \
        --num-l3caches=2 \
        --network=garnet \
        --router-latency=2