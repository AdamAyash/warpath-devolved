from python_requirements import validate_python_requirements
from premake_requirements import validate_premake_requirements
from utils import section, success

validate_python_requirements()
validate_premake_requirements()

section("Warpath-Devolved setup is starting...")
success("Setup completed successfully!")