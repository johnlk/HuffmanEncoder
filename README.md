# HuffmanEncoder

HuffmanEncoder is a program that can be used to compress and decompress files. It utilizes the Huffman coding algorithm for efficient file compression. This README provides an overview of how to use the program and explains the underlying data structures.

## Usage

1. Clone the repository and navigate to the project directory in a terminal or command prompt.

2. Build the executable by running the following command:

```
make
```

This will create an executable named `huffman`.

3. To compress a file, use the following command:

```
huffman -e fileToCompress compressedFileName
```

Replace `fileToCompress` with the path to the file you want to compress and `compressedFileName` with the desired name of the compressed file.

4. To decompress a file, use the following command:

```
huffman -d compressedFileName decompressedFileName
```

Replace `compressedFileName` with the path to the compressed file and `decompressedFileName` with the desired name of the decompressed file.

Note: You can also add the HuffmanEncoder repository to your system's PATH variable, allowing you to execute the `huffman` command from any directory. To do this, open your `.bash_profile` (or equivalent) file and add the following lines at the top or bottom:

```
PATH="~/path/to/HuffmanEncoder/:${PATH}"
export PATH
```

## Compression Efficiency

The compression efficiency of HuffmanEncoder depends on the characteristics of the input file. As an example, testing on a file called `big.txt` (starting at 7.4MB), the file was compressed using HuffmanEncoder to a size of only 4.5MB. This represents a compression ratio of 43.231%. However, it's important to note that the compression efficiency may vary for smaller files. The compressed file contains a header that enables the construction of a Huffman tree during decompression.

## Data Structures

HuffmanEncoder relies on the following data structures:

- **MinHeap**: A minimum heap data structure is used to prioritize characters based on their frequency. It ensures that the characters with the smallest frequency are placed at the top and can be easily removed.

- **Huffman Tree**: The Huffman Tree is a binary tree data structure used to encode and decode the compressed data. Each node in the tree represents either a character or an intermediate sub-tree. The Huffman Tree is constructed by combining the least frequent characters until a complete tree is formed.

Please refer to the source code for a more detailed implementation of these data structures.

Feel free to explore the code and experiment with different files for compression and decompression. If you encounter any issues or have suggestions for improvements, please open an issue on the GitHub repository.