import platform
from enum import Enum

class Platform(Enum): 
    Windows     = 0
    Linux       = 1
    Unknown     = 2

def getCurrentPlatform():
   currentPlatform =  platform.system()
   if(currentPlatform == "Windows"):
      return Platform.Windows
   elif(currentPlatform == "Linux"):
        return Platform.Linux
   else:
        return Platform.Unknown

