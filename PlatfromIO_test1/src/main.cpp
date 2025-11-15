// 注意：某些开发板上的 TXD/RXD 指示灯由 USB-UART (CH340/CP210x 等)
// 驱动，直接在 ESP32 引脚上拉高可能不会点亮这些 LED 或会与 USB 串口芯片发生冲突。
// 以下代码尝试释放 UART0（调用 Serial.end()），然后将 TX0/RX0 对应的 GPIO 设置为输出并拉高，
// 以便驱动可能连接在这些引脚上的 LED。使用前请确认硬件连线，上传固件时可能需要先将引脚
// 恢复为输入或重新启用 Serial，否则无法通过 USB 串口上传或使用串口监视。

#include <Arduino.h>

const int TX0_PIN = 43; // UART0 TX (常见为 GPIO1，S3是43)
const int RX0_PIN = 44; // UART0 RX (常见为 GPIO3，S3是44)

void setup() {
  // 禁用 Serial（如果已启用），以释放 UART0 对应的引脚为普通 GPIO 使用
  Serial.end();
  delay(50); // 等待稳定

  pinMode(TX0_PIN, OUTPUT);
  pinMode(RX0_PIN, OUTPUT);

  // 将 TX/RX 置低，尝试点亮连接在这些引脚上的 LED
  digitalWrite(TX0_PIN, LOW);
  digitalWrite(RX0_PIN, LOW);
}

void loop() {
  // 不需要循环动作，只保持引脚为高电平
  delay(1000);
}