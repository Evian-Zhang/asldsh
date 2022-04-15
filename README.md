# ASLDSH

ASLDSH is a shell where its child processes' and itself's Address Space Layout is Determined even if current linux kernel enables ASLR.

## Build

```console
make asldsh
```

## Usage

Invoke without additional argument:

```console
./asldsh
```

This will spawn a new shell (whose path is determined by env `$SHELL`) with interactive mode.

Invoke with additional argument:

```console
./asldsh echo "hello"
```

This will use the second argument as child process's pathname, and remain arguments as child process's arguments.
