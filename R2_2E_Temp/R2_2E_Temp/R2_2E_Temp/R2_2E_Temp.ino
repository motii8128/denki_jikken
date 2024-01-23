static unsigned long timer = 0;
#define ON HIGH
#define OFF LOW


/*個別I/O制御////////////////////////////////////////////////////////////////////////////
 * （Arduinoのポート数（18個）を超えない場合に使用する。）
 * 使用する場合は｛｝の中にLEDを制御するのに使用するポートを順番に書く。
 * 例）7個のLED（LED1>ポート3,LED2>ポート5・・・・LED7>ポート10）を使用する場合
 *    const char ports[18] = {3,5,7,13,6,8,9}
 */
//const char ports[18] = {/*使用するポートを書く*/};
const char ports[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};  //{}の中にポート番号を設定
static char led[18] = {};                                      //{}の中は何も設定しない
/*[使用方法]
 * 制御したいLEDの番号をONまたはOFFと設定する。
 * 設定後、「LEDControl(【時間】, 【後処理】);」を実行するとLEDに動作が反映される。
 * 【時間】には点灯させたい時間*10mSで点灯時間を設定する。
 * 【後処理】には指定時間経過後の処理を書く。oFF：全部消す　ON：そのまま
 * 例）LED0とLED1を交互に0.5秒ごとに点滅させる。
 *    led[0] = ON;
 *    LEDControl(50, OFF);
 *    led[1] = ON;
 *    LEDControl(50, OFF);
*/
 
/*マトリックス制御////////////////////////////////////////////////////////////////////////////
 * （Arduinoのポート数（18個）を超える個数のLEDを個別に制御したい場合には必須の制御方法）  
 * 使用する場合には以下の「setColomn」に列数を設定し「portColomn」にLEDのアノード側制御端子のポート番号、
 * 「setRow」に行数を設定し「portRow」にLEDのカソード側制御端子のポート番号を設定する必要がある。
 *  例）6×5のマトリックス制御の場合
 *    #define setColomn 7
 *    #define setRow 6
 *    const char portColomn[setColomn] = {2,3,4,5,6,7};
 *    const char portRow[setRow] = {8,9,10,11,12};
 */
#define setColomn 0   //列数を設定
#define setRow 0      //行数を設定
const char portColomn[setColomn] = {};  //{}の中にポート番号を設定
const char portRow[setRow] = {};            //{}の中にポート番号を設定
static char leds[setRow+1][setColomn+1] = {};             //{}の中は何も設定しない
/*[使用方法]
 * 制御したいLEDの番号をLED[行][列]の順で指定しONまたはOFFの動作を設定する。
 * 設定後、「LEDControl(【時間】);」を実行するとLEDに動作が反映される。
 * 【時間】には点灯させたい時間*10mSで点灯時間を設定する。
 * 例）LED0とLED1を交互に0.5秒ごとに点滅させる。
 *    led[0][0] = ON;
 *    led[1][1] = OFF;
 *    LEDControl(50);
 *    led[0][0] = OFF;
 *    led[1][1] = ON;
 *    LEDControl(50);
*/


void loop(){
}
