import PlatformDetection
import WindowsSetup
import LinuxSetup

print("WCC Engine setup is starting.")
platform = PlatformDetection.getCurrentPlatform()

if(platform == PlatformDetection.Platform.Windows):
    WindowsSetup.startWindowsSetup()
elif(platform == PlatformDetection.Platform.Linux):
    LinuxSetup.startLinuxSetup()
else:
    print("Unsuported platform.")