## Magic MIDI Box v1 — ESP32 Bluetooth MIDI Controller

### Português

**Resumo**

Controladora MIDI via Bluetooth (BLE) baseada em ESP32 para acionar notas/samples em um DAW. Publica-se como dispositivo MIDI BLE com o nome "Midi Magic Box v1" e oferece 21 botões físicos distribuídos em 3 linhas.

**Recursos**
- 21 botões (3 linhas × 7 colunas) usando `INPUT_PULLUP` (acionamento por GND)
- Envio de Note On/Off via BLE MIDI
- Canal e offset configuráveis em código
- Debounce simples por atraso de 5 ms

**Requisitos**
- Placa: ESP32 (qualquer DevKit compatível com Arduino)
- IDE Arduino (ou PlatformIO)
- Suporte à placa ESP32 instalado
- Biblioteca que forneça `#include <BLEMidi.h>` (ex.: uma biblioteca BLE MIDI para ESP32 disponível no Library Manager)

**Pinagem (botões → GPIO do ESP32)**
- Linha 1: 5, 18, 19, 21, 3, 22, 23
- Linha 2: 32, 15, 2, 0, 4, 16, 17
- Linha 3: 13, 12, 14, 27, 26, 25, 33

Observação: os botões devem ligar o pino a GND (nível LOW = pressionado), pois o código usa `INPUT_PULLUP`.

⚠️ Nota sobre o GPIO0: o pino 0 (linha 2, quarta posição) é sensível ao boot do ESP32. Se tiver problemas para gravar a placa ou iniciar, considere mover esse botão para outro pino.

**Instalação e Upload**
1. Instale o suporte ao ESP32 na IDE Arduino.
2. Pelo Library Manager, instale uma biblioteca que forneça `BLEMidi.h` (procure por “BLE MIDI ESP32”).
3. Abra `Magic_Midi_Box_v1.ino`.
4. Selecione a placa ESP32 correta e a porta serial.
5. Compile e grave o firmware.

**Emparelhamento e Uso no DAW**
1. Alimente o ESP32; ele anunciará o dispositivo BLE como "Midi Magic Box v1".
2. Emparelhe no sistema operacional (Windows 10/11 com suporte a MIDI BLE, macOS, etc.).
3. No DAW, selecione a entrada MIDI correspondente ao dispositivo BLE.
4. Pressione os botões para enviar notas:
   - Linha 1: notas (1–7) + `Offset`
   - Linha 2: notas (8–14) + `Offset`
   - Linha 3: notas (15–21) + `Offset`
   - Velocidade: 127
   - Canal: `CanalEnvio` (0–15 no código correspondem a canais MIDI 1–16)

**Personalização**
No arquivo `Magic_Midi_Box_v1.ino`, ajuste:

```cpp
// Canal MIDI de envio (0–15 → canais 1–16)
byte CanalEnvio = 15;

// Deslocamento aplicado ao número da nota (ex.: 36 para começar em C2)
byte Offset = 0;

// Debounce (microsegundos)
int delayComando = 5000;
```

Exemplo: para acionar um Drum Rack começando em C2 (nota 36), defina `Offset = 36 - 1` para que a primeira tecla (1 + Offset) caia em 36.

**Solução de Problemas**
- Notas presas: verifique a fiação (botões para GND) e o aterramento comum.
- Emparelhamento BLE: reinicie o ESP32 e remova/adicione o dispositivo no SO; mantenha o ESP32 próximo.
- Boot falhando: evite manter o botão no GPIO0 pressionado durante o reset/boot.

**Estrutura do Projeto**
- `Magic_Midi_Box_v1.ino`: loop principal, leitura dos botões e envio de MIDI BLE.

—

### 🇬🇧 English

**Overview**

Bluetooth (BLE) MIDI controller based on an ESP32 to trigger notes/samples in your DAW. It advertises as "Midi Magic Box v1" and exposes 21 physical buttons in 3 rows.

**Features**
- 21 buttons (3 rows × 7) using `INPUT_PULLUP` (active-low to GND)
- Sends Note On/Off over BLE MIDI
- Configurable channel and note offset
- Simple 5 ms debounce

**Requirements**
- Board: ESP32 DevKit (Arduino-compatible)
- Arduino IDE (or PlatformIO)
- ESP32 board support installed
- A library providing `#include <BLEMidi.h>` (e.g., an ESP32 BLE MIDI library via Library Manager)

**Pinout (buttons → ESP32 GPIO)**
- Row 1: 5, 18, 19, 21, 3, 22, 23
- Row 2: 32, 15, 2, 0, 4, 16, 17
- Row 3: 13, 12, 14, 27, 26, 25, 33

Note: buttons should pull the pin to GND (LOW = pressed) because the code uses `INPUT_PULLUP`.

⚠️ GPIO0 remark: GPIO0 (row 2, position 4) affects ESP32 boot mode. If flashing/booting is problematic, move that button to a different pin.

**Build & Upload**
1. Install ESP32 support in Arduino IDE.
2. From Library Manager, install a library that provides `BLEMidi.h` (search “BLE MIDI ESP32”).
3. Open `Magic_Midi_Box_v1.ino`.
4. Select the correct ESP32 board and serial port.
5. Compile and upload.

**Pairing and DAW Usage**
1. Power the ESP32; it will advertise as "Midi Magic Box v1".
2. Pair it in your OS (Windows 10/11 with BLE MIDI support, macOS, etc.).
3. In your DAW, select the BLE MIDI input.
4. Press buttons to send notes:
   - Row 1: notes (1–7) + `Offset`
   - Row 2: notes (8–14) + `Offset`
   - Row 3: notes (15–21) + `Offset`
   - Velocity: 127
   - Channel: `CanalEnvio` (0–15 in code map to MIDI channels 1–16)

**Customization**
In `Magic_Midi_Box_v1.ino`, tweak:

```cpp
byte CanalEnvio = 15;   // 0–15 → MIDI channels 1–16
byte Offset = 0;        // e.g., 35 to start at MIDI note 36 (C2)
int delayComando = 5000; // debounce in microseconds
```

Example: to start at MIDI note 36 (C2), set `Offset = 35` so the first button (1 + Offset) equals 36.

**Troubleshooting**
- Stuck notes: check wiring (buttons to GND) and common ground.
- BLE pairing: power-cycle ESP32 and re-add the device; keep the board close to the host.
- Boot issues: avoid holding the GPIO0 button during reset/boot.

**Project Layout**
- `Magic_Midi_Box_v1.ino`: main loop, button scanning, BLE MIDI send.

—

Seção de licença: adicione a licença de sua preferência (ex.: MIT) ao repositório.



