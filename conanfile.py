from conans import ConanFile, CMake, tools


class CryptoxConan(ConanFile):
    name = "cpp-netlib-uri"
    version = "0.1"
    license = "Boost"
    author = "madera"
    url = "git@github.com:mmitkevich/uri.git"
    description = "OpenSSL wrappers"
    topics = ("OpenSSL", "md5", "sha256")
    settings = "os", "compiler", "build_type", "arch"
#    options = {"shared": [True, False]}
 # No settings/options are necessary, this is header only
    exports_sources = "*"

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder=".")
        cmake.build()

        # Explicit way:
        # self.run('cmake "%s/src" %s' % (self.source_folder, cmake.command_line))
        # self.run("cmake --build . %s" % cmake.build_config)

    def package(self):
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.dylib*", dst="lib", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["uri"]


