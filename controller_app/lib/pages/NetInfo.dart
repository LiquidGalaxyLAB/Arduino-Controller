import 'package:flutter/material.dart';
import 'package:controllerapp/main.dart';

import '../BluetoothPage.dart';

class NetInfoPage extends StatefulWidget {
  static final tag = 'netinfo-page';
  NetInfoPage({Key key}):super(key:key);
  @override
  _NetInfoPageState createState() => _NetInfoPageState();
}

class _NetInfoPageState extends State<NetInfoPage> {
  final _LGIP = TextEditingController();
  final _SSID = TextEditingController();
  final _PASSWORD = TextEditingController();
  bool _showPassword = true;

  @override
  void dispose() {
    _LGIP.dispose();
    _SSID.dispose();
    _PASSWORD.dispose();
    super.dispose();
  }
  @override
  Widget build(BuildContext context) {
    var size = MediaQuery.of(context).size;
    return Scaffold(
      appBar: AppBar(
        title: Text("Network Information"),
      ),
      body: Container(
          decoration: BoxDecoration(
              gradient: LinearGradient(
                  begin: Alignment.topCenter,
                  end: Alignment.bottomCenter,
                  colors:[
                    Colors.white10,
                    Colors.white
                  ]
              )
          ),
          child: Column(
            children: <Widget>[
              Container(height:45),
              Container(
                //height: 100,
                  width: size.width*.8,
                  //color: Colors.green,
                  child: Card(
                    shape: RoundedRectangleBorder(
                      side: BorderSide(color: Colors.blue,width: 3),
                        borderRadius: BorderRadius.circular(20)),
                    child: Container(
                      child: Column(
                        children: <Widget>[
                          Container(height:30),
                          Container(
                            width: size.width*.7,
                            child: TextFormField(
                              keyboardType: TextInputType.number,
                              controller: _LGIP,
                              decoration: InputDecoration(
                                labelText: "LG Master IP",
                                labelStyle: TextStyle(color: Colors.black87),
                                contentPadding: EdgeInsets.fromLTRB(30, 10,20, 10),
                                border: OutlineInputBorder(borderRadius: BorderRadius.circular(32)),
                              ),
                            ),
                          ),
                          Container(height:15),
                          Container(
                            width: size.width*.7,
                            child: TextFormField(
                              keyboardType: TextInputType.text,
                              controller: _SSID,
                              decoration: InputDecoration(
                                labelText: "SSID",
                                labelStyle: TextStyle(color: Colors.black87),
                                contentPadding: EdgeInsets.fromLTRB(30, 10,20, 10),
                                border: OutlineInputBorder(borderRadius: BorderRadius.circular(32)),
                              ),
                            ),
                          ),
                          Container(height:15),
                          Container(
                            width: size.width*.7,
                            child: TextFormField(
                              keyboardType: TextInputType.text,
                              obscureText: _showPassword,
                              controller: _PASSWORD,
                              decoration: InputDecoration(
                                  labelText: "PASSWORD",
                                  labelStyle: TextStyle(color: Colors.black87),
                                  contentPadding: EdgeInsets.fromLTRB(30, 10,20, 10),
                                  border: OutlineInputBorder(borderRadius: BorderRadius.circular(32)),
                                  suffixIcon: GestureDetector(
                                    child: Icon(_showPassword == false ? Icons.visibility :Icons.visibility_off,size: 30,),
                                    onTap: (){
                                      setState(() {
                                        _showPassword =! _showPassword;
                                      });
                                    },
                                  )
                              ),
                            ),
                          ),
                          Container(height:30),
                        ],
                      ),
                    ),
                  )
              ),
              Container(height:20),
              Container(
                  width: size.width*.7,
                  height: 50,
                  color: Colors.white,
                  child: RaisedButton(
                      child: Text("Save to send", style: TextStyle(
                          color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                      ),
                      color: Colors.blue,
                      onPressed: (){
                        netIP = _LGIP.text;
                        netSSID = _SSID.text;
                        netPASSWORD = _PASSWORD.text;
                        setState(() {
                          controlBottonSend = 'NetInfo';
                        });
                        Navigator.of(context).push(MaterialPageRoute(builder: (context)=>BluetoothPage()));
                      }
                  )
              ),
            ],
          )
      ),

    );
  }
}
