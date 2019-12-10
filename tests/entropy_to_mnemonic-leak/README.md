Instructions
------------
In order to perform the execution resulting in a leak simply call the `perform-leak.sh` script:
```
$ ./perform-leak.sh
```

It patches one OpenSSL function in order to make it fail, which consequently results in triggering a return path from `entropy_to_mnemonic`, that does not free bytes pointed to by `bytes`.

The memory leak is of 17 bytes, which corresponds with 16 bytes for input entropy and 1 byte for the checksum.
