# Arduino Library for the GI Sound Chip AY-3-8910

**English follows Japanese**

# 日本語

このライブラリにより簡単に AY-3-8910 を制御できます．  
各チャンネルの音量とトーンのみ制御できます．

## 使い方

以下のようにして初期化します．

```cpp
#include <AY-3-8910.h>

/* 以下は実際の接続に合わせて変更してください */
const int RESET_PIN =  8;
const int BC1_PIN   = A5;
const int BDIR_PIN  = A4;

AY_3_8910 PSG(RESET_PIN, BC1_PIN, BDIR_PIN);

void setup() {
  PSG.init();
  PSG.set_volume(A, 0b1111);
  PSG.set_volume(B, 0b1111);
  PSG.set_volume(C, 0b1111);
}
```

音を鳴らすためには以下の関数を使用します．  
第一引数にチャンネル，第二引数にライブラリにより定義されたインデックスを指定します．

以下は A チャンネルから C4 (ド) を出力する例です．

```cpp
PSG.tone_out(A, NOTE_C4);
```

音を止めるためには以下の関数を使用します．

```cpp
PSG.tone_mute(A);
```

# English

This library controls AY-3-8910 simply.  
It can controls only volume and tone each channel.

## How to use

Initialize like this.

```cpp
#include <AY-3-8910.h>

/* The following should be changed to match the actual connection */
const int RESET_PIN =  8;
const int BC1_PIN   = A5;
const int BDIR_PIN  = A4;

AY_3_8910 PSG(RESET_PIN, BC1_PIN, BDIR_PIN);

void setup() {
  PSG.init();
  PSG.set_volume(A, 0b1111);
  PSG.set_volume(B, 0b1111);
  PSG.set_volume(C, 0b1111);
}
```

To output sound, use function shown below.  
The first argument is the channel and the second is the index defined by the library.

The following is an example of outputting C4 from channel A.

```cpp
PSG.tone_out(A, NOTE_C4);
```

To stop sound, use function shown below.

```cpp
PSG.tone_mute(A);
```
