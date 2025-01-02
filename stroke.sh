#!/bin/bash

# Check if the argument is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <filename_base>"
  exit 1
fi

# Get the base name from the first argument
base_name=$1
cpp_file="${base_name}.cpp"
input_file="${base_name}.in"
output_file="${base_name}.out"
mkdir ${base_name}
cd ${base_name}

# Create the .cpp file with the necessary includes and code
cat <<EOF > $cpp_file
#include <bits/stdc++.h>

using namespace std;
ifstream fin("${input_file}");
ofstream fout("${output_file}"); 

int main() {

    cout << "Hello World" << endl;
    return 0;

}
EOF

# Create the .in and .out files
touch "$input_file" "$output_file"

echo "Succesfully created your new coding environment in the ${base_name} directory!"