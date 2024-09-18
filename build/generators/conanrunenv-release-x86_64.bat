@echo off
chcp 65001 > nul
setlocal
echo @echo off > "%~dp0/deactivate_conanrunenv-release-x86_64.bat"
echo echo Restoring environment >> "%~dp0/deactivate_conanrunenv-release-x86_64.bat"
for %%v in (PATH OPENSSL_MODULES) do (
    set foundenvvar=
    for /f "delims== tokens=1,2" %%a in ('set') do (
        if /I "%%a" == "%%v" (
            echo set "%%a=%%b">> "%~dp0/deactivate_conanrunenv-release-x86_64.bat"
            set foundenvvar=1
        )
    )
    if not defined foundenvvar (
        echo set %%v=>> "%~dp0/deactivate_conanrunenv-release-x86_64.bat"
    )
)
endlocal


set "PATH=C:\Users\Beyioku\.conan2\p\doxyg9774c0925daa6\p\bin;C:\Users\Beyioku\.conan2\p\cmake98309fcbb52ab\p\bin;%PATH%"
set "OPENSSL_MODULES=C:\Users\Beyioku\.conan2\p\opens1196ee88005bb\p\lib\ossl-modules"