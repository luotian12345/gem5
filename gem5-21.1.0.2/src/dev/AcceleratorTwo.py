from m5.params import *
from m5.objects.Device import DmaDevice
from m5.objects.Device import BasicPioDevice


class AcceleratorTwo(BasicPioDevice):
    type = 'AcceleratorTwo'
    cxx_header = "dev/acceleratortwo.hh"
    cxx_class = 'gem5::AcceleratorTwo'

    pio_size = Param.Addr(0x04, "PIO size")
    traffic_gen_1 = Param.TrafficGen("traffic generator in accelerator")