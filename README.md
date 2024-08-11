# smart-trash

## Development

### Prerequisites

- [Arduino CLI](https://arduino.github.io/arduino-cli/0.35/getting-started/) (`brew install arduino-cli`)

### Compile Sketch

```bash
arduino-cli compile --fqbn arduino:avr:nano SmartTrash
```

### Upload Sketch

```bash
arduino-cli upload -p /dev/cu.usbserial-140 --fqbn arduino:avr:nano SmartTrash
```

### Compile and Upload

```bash
bash ./scripts/compile-and-upload.sh
```
