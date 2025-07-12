import os
import zipfile
import subprocess
from pathlib import Path
from urllib.request import urlretrieve
from Utilities import Loader

print("WCC Engine setup is starting.")
print("Do you wish to download \"Premake\"? y/n ")

PREMAKE5_DOWNLOAD_URL = ("https://github.com/premake/premake-core/releases/download/v5.0.0-beta6/premake-5.0.0-beta6-windows.zip")
PREMAKE5_ZIP_FILE_NAME = "premake.zip"
VENDOR_FOLDER_RELATIVE_PATH = "/vendor/bin"
ANIMATION_TIMEOUT = 0.05

shouldDownloadPreamke = input()
if(shouldDownloadPreamke == "y" or shouldDownloadPreamke == "yes"):
   animationLoader = Loader("Generating project files... ", "Project setup is complete.", ANIMATION_TIMEOUT).start()
   Path(VENDOR_FOLDER_RELATIVE_PATH).mkdir(parents=True, exist_ok=True)
   urlretrieve(PREMAKE5_DOWNLOAD_URL, PREMAKE5_ZIP_FILE_NAME)
elif(shouldDownloadPreamke != "n" and shouldDownloadPreamke != "no"):
    print("Incorrect input.")
    
with zipfile.ZipFile(PREMAKE5_ZIP_FILE_NAME, 'r') as zipFileReference:
    zipFileReference.extractall(VENDOR_FOLDER_RELATIVE_PATH)
     
os.remove(PREMAKE5_ZIP_FILE_NAME)
subprocess.call(["/vendor/bin/premake5.exe", "vs2022"])
animationLoader.stop()
print("WCC Engine setup has completed.")
