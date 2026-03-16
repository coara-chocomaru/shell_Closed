# shell_closed

**adbブロック用簡易ラッパー**
- **USBデバッグ経由のあらゆるシェル利用を即座に禁止**します！

- `adb shell` → 即「shell Closed」表示＋終了  
- `adb shell -c "コマンド"` / `adb shell "コマンド"` → すべてブロック  
- init.rc・アプリ内シェル・recoveryなどは**完全に正常動作**
- recovery内のshを差し替えればadbからのshの利用を封じることも出来ます

---
