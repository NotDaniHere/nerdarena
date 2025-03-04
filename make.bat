@echo off
:: Check if an argument is provided
if "%~1"=="" (
    echo Usage: %~nx0 filename_base
    exit /b 1
)

:: Get the base name from the first argument
set "base_name=%~1"
set "cpp_file=%base_name%.cpp"
set "input_file=%base_name%.in"
set "output_file=%base_name%.out"

:: Create the .cpp file
(
echo #include <iostream>
echo #include <fstream>
echo #include <string>
echo.
echo int main() {
echo     std::ifstream inputFile("%input_file%");
echo     std::ofstream outputFile("%output_file%");
echo.
echo     if (!inputFile) {
echo         std::cerr << "Error opening input file: %input_file%" << std::endl;
echo         return 1;
echo     }
echo.
echo     if (!outputFile) {
echo         std::cerr << "Error opening output file: %output_file%" << std::endl;
echo         return 1;
echo     }
echo.
echo     std::string line;
echo     while (std::getline(inputFile, line)) {
echo         // Process line (you can modify this part)
echo         outputFile << line << std::endl;
echo     }
echo.
echo     inputFile.close();
echo     outputFile.close();
echo     return 0;
echo }
) > "%cpp_file%"

:: Create empty .in and .out files
type nul > "%input_file%"
type nul > "%output_file%"

echo Generated %cpp_file% with ifstream and ofstream using %input_file% and %output_file%.
echo Created empty files: %input_file% and %output_file%.

