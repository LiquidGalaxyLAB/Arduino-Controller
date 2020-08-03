import 'package:flutter/material.dart';

class VoicePage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    var appBar = AppBar(title: Text("Voice Record Commands"));
    var size = MediaQuery.of(context).size;

    return Scaffold(
      appBar: appBar,
      body: Container(
        width: size.width,
        height: size.height,
        child: Column(
          children: <Widget>[
            SizedBox(height: 40,),
            Center(
              child: Container(
                child: Text("Click each Button to Record the Command",style: TextStyle(
                    color: Colors.blue,fontSize: 30,fontWeight: FontWeight.w700),
                ),
              ),
            ),
            SizedBox(height: 40,),
            Expanded(
              child: Container(),
            ),
          ],
        ),
      ),
    );

  }
}
