<!-- TABLE OF CONTENTS -->
## Table of Contents

* [Project Goals](#project-goals)
* [About the Project](#about-the-project)
  * [Built With](#built-with)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
* [Usage](#usage)
* [Implementation Details](#implementation-details)
* [Considerations](#considerations)

<!-- ABOUT THE PROJECT -->
## Project Goals
1. Use the primitives *fork*, *wait*, *exec*, *exit* for concurrent process management
2. Use the primitive thread functions
3. Develop a communication mechanism of shared memory for communication between threads
4. Use primitives to measure the execution time between processes/threads
5. Use primitives to manage either binary or text files

## About the project
Cryptography is a set of strategies that allows us to transform the information with the goal of hiding it from non authorized third parties. The most used algorithms rely on substitution techniques to modify the original text and obtain the cyphered text. A very old and popular algorithm is *caesar's code*, that uses only one substitution and it's the following:

Every letter of the original text is translated for the letter that is 2 positions ahead in the alphabet, the letters that are in the end of the alphabet (Y, Z) are replaced by (A, B) respectively. For example

*I will only tell you tomorrow morning in the library*

Would end up as:

*K yknn qpna vgnn apw vqoqttqy oqtokpi kp vjg nkdtcta*

Another very well known algorithm is "Murcielago code", its substitution is the following:

M | U | R | C | I | E | L | A | G | O
0   1   2   3   4   5   6   7   8   9

This repository has 3 programs written in C of the crypting and decrypting program, a sequential version and 2 concurrent versions, one with processes and one with threads, in the concurrent versions, given that crypting/descrypting is clearly parallelizable it will be built with a 3 level tree of processes/threads: root, middle and leaves. In order to cypher, the root process will receive a file with the word that will be modified, the blank spaces will be deleted, the leaves will apply the caesar's code, the middle processes/threads will apply Murcielago's code for the second phase of substitution, the root process will receive the cyphered text of all their children and will concatenate in order the content of the children's files to finally obtain the cyphered text and save it in another text file.

The decyphering program is exactly the opposite, given the cyphered text in a text file, it will obtain the clear text without blank spaces or tabs. That means that the leaves processes/threads will execute the reverser Murcielago code. The output files will be received by the superior level and will apply the caesar code in reverse. Finally, the created files will be received by the root to concatenate all the files and obtain the whole clear word.

### Built With

* [C]()


<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these simple steps.

### Prerequisites

This is an example of how to list things you need to use the software and how to install them.
* [Ubuntu](https://ubuntu.com/download/desktop)

* gcc

```sh
sudo apt update
sudo apt install build-essential
sudo apt-get install manpages-dev
```

To make sure gcc was installed execute

```sh
gcc --version
```

### Usage
 
1. Sequencial command line
```sh
cript <-c/-d> InputFileName
```

2. Process command line
```sh
cript_p <-c/-d> NumberOfChildren InputFileName OutputFileName
```

3. Thread command line
```sh
cript_t <-c/-d> NumberOfChildren InputFileName OutputFileName
```

## Implementation details

**Process implementation**: Initially, the root process will distribute the work between their *n* children in equal parts as long as it is possible. In any case, each children process will get a piece of text assigned to cypher/decypher. Each process will receive of its parent process the following values:

1. The file name of the text to cypher/decypher
2. The number of characters to cypher/decypher
3. The position of the text that will be cyphered/decyphered

Each process will create a file called PID.txt. The middle processess will read the files created by their children, will make the next process of cypher/descypher, will create the correspondent files (PID.txt), will delete the files generated by their children and end. Finally, the root process will do its job and create the output file. The leave processes will open the initial file, will take the piece of text that corresponds to it, will do the job of cypher/decypher and creates its file (which name will be PID.txt) as a result.

**Threads implementation**: The communication will be done using parameters at the moment the threads are created. In the thread version children files won't be created.

## Considerations
1. It will be assumed that the input file is correct: Only contains letters (numbers won't be considered). 
2. The compilation of the program will be done with the help of a Makefile
3. The system calls will be validated with perror()
4. The input arguments will be verified (number of children must be a positive integer, etc) 