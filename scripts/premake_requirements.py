
import os
import globals
from utils import load_animation, success, prompt_with_default, download_zip

def validate_premake_requirements():
	load_animation("Validating premake requirements...")
	if not __is_premake_installed():
		installPremake = prompt_with_default("Premake is not installed do you wish to install it [y/n]", 'y')
		__install_premake()
	

def __is_premake_installed() -> bool:
		return os.path.exists("vendor/bin/premake5.exe")

def __install_premake():
	load_animation("Installing premake...")
	download_zip(globals.premakeDownloadUrl,"../vendor/bin/")
	success("Premake installed successfully!")
