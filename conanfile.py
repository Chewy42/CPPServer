from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, CMakeDeps
from conan.tools.build import check_min_cppstd

class CPPServerConan(ConanFile):
    name = "CPPServer"
    version = "0.1"
    settings = "os", "compiler", "build_type", "arch"
    requires = "boost/1.85.0"
    generators = "CMakeToolchain", "CMakeDeps"
    exports_sources = "CMakeLists.txt", "src/*"

    def configure(self):
        if self.settings.os == "Macos":
            self.settings.compiler.libcxx = "libc++"

    def validate(self):
        check_min_cppstd(self, "17")  # Ensure C++17 standard

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["CPPServer"]
