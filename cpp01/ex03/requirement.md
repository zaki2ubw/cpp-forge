## Weaponクラス
  - 武器名typeをstringで持つ
  - typeを変更するsetTypeを持つ
  - typeを読み取り専用で返すgetTypeを持つ

## HumanAクラス
  - 名前myNameを持つ
  - 必ず存在するWeaponへの参照を持つ
  - 名前とWeaponを受け取るコンストラクタを持つ
  - attackで名前と現在の武器名を出力する

## HumanBクラス
  - 名前myNameを持つ
  - Weaponへのポインタを持つ
  - 生成時は武器なしでよい
  - 名前を受け取るコンストラクタを持つ
  - 後から武器をセットするsetWeaponを持つ
  - attackで名前と現在の武器名を出力する
