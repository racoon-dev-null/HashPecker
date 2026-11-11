<h1 align="center">HashPecker</h1>

<p align="center">
  A fast, lightweight MD5 password cracker written in pure C.<br>
 

---

## Overview

**HashPecker** demonstrates low-level file handling, memory management, and dictionary-based hash matching without heavy external system dependencies.

## Features

* **Standalone Architecture:** Uses a built-in MD5 implementation (`md5.c` / `md5.h`), making it easily portable across Linux and Windows.
* **Lightweight & Fast:** Written in pure C for high-speed dictionary attacks.
* **CLI Ready:** Accepts target hashes and custom wordlists directly via command-line arguments.

## Compilation

### Linux
```bash
gcc -O3 hashpecker.c md5.c -o hashpecker
```

### Windows (MinGW / GCC)
```powershell
gcc -O3 hashpecker.c md5.c -o hashpecker.exe
```

## Usage

Pass the target MD5 hash and the path to your wordlist as arguments:

```bash
./hashpecker <md5_hash> <wordlist_file>
```

### Example
```bash
./hashpecker e10adc3949ba59abbe56e057f20f883e wordlist.txt
```

## Disclaimer

*This tool is developed strictly for educational purposes, authorized security testing, and CTF challenges. Do not use it on systems or data you do not have explicit permission to test.*
