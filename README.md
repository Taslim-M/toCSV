# toCSV
Convert all files in a directory to CSV [Windows]. Check cpp file for code. Ensure latest version of C++ is being used.
CSV can allow data analyis via spreadsheet softwares such as Excel.
Note that it requires Filesystem. If your Visual Studio does not recognize filesystem, try visiting https://stackoverflow.com/questions/50668814/vs2017-e0135-namespace-std-has-no-member-filesystem for help.
If you do not wish to delete the file after conversion, comment the line 50 remove(fname.c_str()); .
To prevent the executable file from being deleted, keep it outside the directory of the files being converted.
