<h1 align="center">HashPecker</h1>

<p align="center">
  A fast, lightweight multi-hash password cracker written in pure C.<br>
  Designed as a core utility for the future <b>Anteater OS</b> ecosystem.
</p>

---

## Overview

**HashPecker** supports **MD5**, **SHA-1**, and **SHA-256** algorithms. It demonstrates low-level file handling, memory management, and dictionary-based hash matching without heavy external system dependencies.

## Features

* **Multi-Hash Support:** Supports MD5, SHA-1, and SHA-256 hashing algorithms.
* **Standalone Architecture:** Uses built-in cryptographic implementations (`md5.c`, `sha1.c`, `sha256.c`), making it easily portable across Linux and Windows.
* **Lightweight & Fast:** Written in pure C for high-speed dictionary attacks.
* **CLI Ready:** Accepts target algorithms, hashes, and custom wordlists directly via command-line arguments.

## Compilation

### Linux
```bash
gcc -O3 hashpecker.c md5.c sha1.c sha256.c -o hashpecker
```

### Windows
```powershell
gcc -O3 hashpecker.c md5.c sha1.c sha256.c -o hashpecker.exe
```

## Usage

Pass the target algorithm, hash, and path to your wordlist as arguments:

```bash
./hashpecker <md5|sha1|sha256> <hash> <wordlist_file>
```

### Examples
```bash
./hashpecker md5 e10adc3949ba59abbe56e057f20f883e wordlist.txt
./hashpecker sha1 5baa61e4c9b93f3f0682250b6cf8331b7ee68fd8 wordlist.txt
./hashpecker sha256 8d969eef6ecad3c29a3a629280e686cf0c3f5d5a86aff3ca12020c923adc6c92 wordlist.txt
```

## Disclaimer

*This tool is developed strictly for educational purposes, authorized security testing, and CTF challenges. Do not use it on systems or data you do not have explicit permission to test.*

---
<p align="center">
  Built by <b>Racoon</b> (<code>racoon-dev-null</code>)
