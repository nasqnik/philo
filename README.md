# Philosophers

A C implementation of the Dining Philosophers problem using POSIX threads and mutexes.

## Overview

`philo` simulates philosophers who repeatedly:
- take two forks,
- eat,
- sleep,
- think.

The simulation stops when:
- a philosopher dies (does not eat within `time_to_die`), or
- every philosopher has eaten `number_of_times_each_philosopher_must_eat` times (when this optional argument is provided).

## Requirements

- `cc` compiler
- `make`
- POSIX threads (`pthread`)

## Build

```bash
make
```

This creates the executable:
- `./philo`

Useful make targets:
- `make clean` - remove object files
- `make fclean` - remove object files and binary
- `make re` - rebuild from scratch

## Usage

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

All values must be positive integers.

### Arguments

- `number_of_philosophers`: number of philosopher threads (and forks)
- `time_to_die`: max time in milliseconds without eating before death
- `time_to_eat`: eating duration in milliseconds
- `time_to_sleep`: sleeping duration in milliseconds
- `number_of_times_each_philosopher_must_eat` (optional): stop once all philosophers eat at least this many times

## Examples

Run until someone dies:

```bash
./philo 5 800 200 200
```

Run until all philosophers eat at least 7 times:

```bash
./philo 5 800 200 200 7
```

## Output

The program prints timestamped state changes:
- `has taken a fork`
- `is eating`
- `is sleeping`
- `is thinking`
- `died`

Timestamps are milliseconds since simulation start.

## Project Structure

- `main.c` - argument flow, initialization, and startup
- `init.c` - parsing to runtime config and resource initialization
- `thredding.c` - philosopher routine and thread lifecycle
- `fork_utils.c` - fork ordering, locking, and unlock logic
- `actions.c` - eat/sleep/think actions and precise sleep helper
- `monitor.c` - death detection and meal-count termination
- `parsing_utils.c` - argument validation and error messages
- `philo_utils.c` - time, conversion, logging, cleanup helpers
- `philo.h` - shared structs, enums, and function declarations

## Notes

- Fork access is protected with mutexes.
- Logging is protected by a print mutex to avoid interleaved output.
- Death/termination state is shared and synchronized across threads.
