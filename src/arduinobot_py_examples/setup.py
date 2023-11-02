from setuptools import setup
import os
from glob import glob

package_name = "arduinobot_py_examples"

setup(
    name=package_name,
    version="0.0.0",
    packages=[package_name],
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
        (os.path.join("share", package_name, "nodes"), glob("nodes/*.py")),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="vibi",
    maintainer_email="vaibhavshende1903@gmail.com",
    description="TODO: Package description",
    license="TODO: License declaration",
    tests_require=["pytest"],
    entry_points={
        "console_scripts": [
            "simple_publisher = nodes.simple_publisher_node:main",
            "simple_subscriber = nodes.simple_subscriber_node:main",
        ],
    },
)
