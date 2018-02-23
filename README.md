# HuffmanEncoder
This program serves to both encode and decode files. Or in layman's terms, compress and decompress files. To use download 
git repository then navigate to directory within a terminal or command prompt. Type `make` to constuct the excutable 
named `huffman`. To compress a file type `huffman -e fileToCompress compressedFileName`. Next to decompress the file type
`huffman -d compressFileName decompressedFileName`. <br><br>

You may also add your add this git repository to you PATH which would allow you to compress from any directory.
Open your .bash_profile and add these lines `PATH="~/somePath/HuffManEncoder/:${PATH}"` and next `export PATH`.

# Compression Efficiency
Testing on a file in the directory titled `big.txt` starting at 7.4MB, it was compressed with `huffman` to create a file
only 4.5MB in size. This is a compression of 43.231%. Keep in mind however that this file is particularly large and 
the compression of smaller files will have less efficiency. This is because the compressed file contains a header allowing
for the construction of a huffman tree when it comes time to decompress the file.

# Data Structures
When building a huffman tree, it's important to start by creating sub-trees from the least frequent characters 
in a file. This required I construct a MinHeap that would allow the characters with the smallest frequency at 
the top and easily removeable. <br><br>
Beyond a MinHeap, the Huffman Tree was a data type that had to be implemented. It ended up being a binary tree with no
nodes having either 2 or no children. 
