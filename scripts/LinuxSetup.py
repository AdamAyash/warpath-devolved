from Utilities import Loader
import subprocess
from pathlib import Path
from urllib.request import urlretrieve
import os

PREMAKE5_DOWNLOAD_URL = ("https://github.com/premake/premake-core/releases/download/v5.0.0-beta7/premake-5.0.0-beta7-linux.tar.gz")
VENDOR_FOLDER_RELATIVE_PATH = "vendor/bin/"
PREMAKE5_ZIP_FILE_NAME = "premake.tar.gz"
ANIMATION_TIMEOUT = 0.05

def startLinuxSetup():
    shouldDownloadPreamke = input("Do you wish to download \"Premake\"? y/n ")
    if(shouldDownloadPreamke == "y" or shouldDownloadPreamke == "Y" or shouldDownloadPreamke == "yes"):
        animationLoader = Loader("Generating project files... ", "Project setup is complete.", ANIMATION_TIMEOUT).start()
        Path(VENDOR_FOLDER_RELATIVE_PATH).mkdir(parents=True, exist_ok=True)
        urlretrieve(PREMAKE5_DOWNLOAD_URL, VENDOR_FOLDER_RELATIVE_PATH + PREMAKE5_ZIP_FILE_NAME)
    elif(shouldDownloadPreamke != "n" and shouldDownloadPreamke != "no"):
        print("Incorrect input.")

    # subprocess.call(["tar -x -f " + "../" + VENDOR_FOLDER_RELATIVE_PATH + PREMAKE5_ZIP_FILE_NAME])
    subprocess.call([VENDOR_FOLDER_RELATIVE_PATH +" premake gmake"])