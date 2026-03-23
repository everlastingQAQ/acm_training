@echo off
chcp 65001 >nul
setlocal enabledelayedexpansion

echo Compiling programs...
g++ data.cpp -o data.exe -O2 -std=c++23
if errorlevel 1 goto compile_fail
g++ std.cpp -o std.exe -O2 -std=c++23
if errorlevel 1 goto compile_fail
g++ my.cpp -o my.exe -O2 -std=c++23
if errorlevel 1 goto compile_fail

echo Compilation successful!
echo.

set /a count=0
:loop
set /a count+=1
echo Testing case !count!...

:: 生成 1 组数据（seed=count，方便复现）
data.exe !count! > data.in
if errorlevel 1 (
    echo [ERROR] data.exe crashed at case !count!
    pause
    exit /b
)

std.exe < data.in > std.out
if errorlevel 1 (
    echo [ERROR] std.exe crashed at case !count!
    pause
    exit /b
)

my.exe < data.in > my.out
if errorlevel 1 (
    echo [ERROR] my.exe crashed at case !count!
    pause
    exit /b
)

fc /n /w std.out my.out >nul
if errorlevel 1 (
    echo ========================================
    echo Found different output at case !count!
    echo ========================================
    echo Input data saved in: data.in
    echo Standard output saved in: std.out
    echo Your output saved in: my.out
    echo Reproduce: data.exe !count! ^> data.in
    pause
    exit /b
)

:: 每 100 轮打印一次进度（正确写法：用 set /a 做取模）
set /a mod=count%%100
if !mod! EQU 0 echo Passed !count! cases...

goto loop

:compile_fail
echo Compilation failed!
pause
exit /b