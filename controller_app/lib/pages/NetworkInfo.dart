import 'package:flutter/material.dart';


class NetworkInfo extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    var size = MediaQuery.of(context).size;
    final TextEditingController _SSID  = new TextEditingController();
    final TextEditingController _PASSWORD  = new TextEditingController();

    return Scaffold(
      appBar: AppBar(
        title: Text("Network Info"),
      ),
      body:    Container(
        width: size.width,
        height: size.height,
        color: Colors.white,
        child: Column(
          children: <Widget>[
            Container(
              height:90,
              color: Colors.white,
            ),
            Container(
              width: size.width*.7,
              color: Colors.white,
              child: TextFormField(
                controller: _SSID,
                decoration: InputDecoration(
                    hintText: 'SSID',
                    contentPadding: EdgeInsets.fromLTRB(20, 10,20, 10),
                    border: OutlineInputBorder(borderRadius: BorderRadius.circular(32))
                ),
              ),
            ),
            Container(
              height:15,
              color: Colors.white,
            ),
            Container(
              width: size.width*.7,
              color: Colors.white,
              child: TextFormField(
                keyboardType: TextInputType.text,
                controller: _SSID,
                decoration: InputDecoration(
                    hintText: 'PASSWORD',
                    contentPadding: EdgeInsets.fromLTRB(20, 10,20, 10),
                    border: OutlineInputBorder(borderRadius: BorderRadius.circular(32))
                ),
              ),
            ),
            Container(
              height:25,
              color: Colors.white,
            ),
            Container(
              width: size.width*.7,
              height: 50,
              color: Colors.white,
              child: RaisedButton(
                child: Text("Send info to Controller", style: TextStyle(
                    color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                ),
                  color: Colors.blue,
                  onPressed: (){}
              )
            ),
          ],
        ),
      ),

    );
  }
}