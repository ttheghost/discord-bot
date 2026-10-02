from conan import ConanFile
from conan.tools.cmake import cmake_layout


class DiscordBot(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("dpp/10.0.35")

    def layout(self):
        cmake_layout(self)
