# Redix

I built Redix because I wanted to understand how Redis works,
not just use it. So I built my own version from scratch in C++.

It's not production ready. It's not trying to be.
It's a learning project that actually works.

---

## What it does

Redix is an in-memory key-value store that listens for TCP
connections and responds to simple commands — just like Redis.

You can store a value, get it back, delete it, check if it
exists. That's it for now. More coming.

---

## Why C++

I come from C. C++ gives me the same control over memory
but with cleaner abstractions. No garbage collector,
no magic — just code that does exactly what you tell it.

---

## Getting started

**Build:**
```bash
make
```

**Run:**
```bash
./redix
```

**Connect:**
```bash
telnet localhost 6379
```

---

## Commands

SET key value   → store something
GET key         → get it back
DEL key         → delete it
EXISTS key      → is it there?

**Example session:**

SET name imad
OK
GET name
imad
EXISTS name
1
DEL name
OK
GET name
(nil)


---

## How it works
you type a command
↓
TCP server receives it
↓
parser figures out what you want
↓
storage engine executes it
↓
server sends back the result

Three layers. Each one does one job. Nothing more.

---

## Project structure
redix/
├── main.cpp      → starts everything
├── server.cpp    → handles TCP connections
├── parser.cpp    → reads and validates commands
├── store.cpp     → stores your data
└── Makefile      → builds the project

---

## Roadmap

- [x] Project structure
- [ ] Storage engine
- [ ] Command parser
- [ ] TCP server
- [ ] Hash support (HSET/HGET)
- [ ] List support (LPUSH/RPOP)

---

## Author

Imad Bengreine
github.com/ImadBengreine

*First year DUT student in Morocco building things
to understand how they work.*