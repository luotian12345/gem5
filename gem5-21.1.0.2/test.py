import types
import importlib.machinery
loader = importlib.machinery.SourceFileLoader('chi_configs','/home/luot/gem5-21.1.0.2/configs/example/noc_config/2x2.py')
chi_configs = types.ModuleType(loader.name)

#loader.exec_module(chi_configs)
print(chi_configs)