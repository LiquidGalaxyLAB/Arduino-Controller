import 'package:flutter/material.dart';


class Info extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    var size = MediaQuery.of(context).size;

    return Scaffold(
      appBar: AppBar(
        title: Text("About this project"),
      ),
      body:    Center(
        widthFactor: size.width*.5,
        child: Text("https://github.com/LiquidGalaxyLAB/Arduino-Controller", style: TextStyle(
            color: Colors.black,fontSize: 20,fontWeight: FontWeight.w700),
        ),
      ),

    );
  }
}