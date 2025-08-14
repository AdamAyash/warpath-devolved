from Utilities import Loader
import subprocess
from pathlib import Path
from urllib.request import urlretrieve
import Globals
import os

def startLinuxSetup():
    shouldDownloadPremake = input("Do you wish to download \"Premake\"? y/n ")
    if(shouldDownloadPremake == "y" or shouldDownloadPremake == "Y" or shouldDownloadPremake == "yes"):
        animationLoader = Loader("Generating project files... ", "Project setup is complete.", Globals.ANIMATION_TIMEOUT).start()
        Path(Globals.VENDOR_FOLDER_RELATIVE_PATH).mkdir(parents=True, exist_ok=True)
        urlretrieve(Globals.PREMAKE5_LINUX_DOWNLOAD_URL, Globals.VENDOR_FOLDER_RELATIVE_PATH + Globals.PREMAKE5_ARCHIVE_FILE_NAME)
    elif(shouldDownloadPremake != "n" and shouldDownloadPremake != "no"):
        print("Incorrect input.")

    # subprocess.call(["tar -x -f " + "../" + VENDOR_FOLDER_RELATIVE_PATH + PREMAKE5_ZIP_FILE_NAME])
    subprocess.call([Globals.VENDOR_FOLDER_RELATIVE_PATH +" premake gmake"])