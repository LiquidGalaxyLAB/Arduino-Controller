import 'package:flutter/material.dart';


class UltrasonicPage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
   // var size = MediaQuery.of(context).size;

    return Scaffold(
      appBar: AppBar(
        title: Text("Ultrasonic Setup"),
      ),
      body:    Center(
        child: Container(
          width: 150,
          height: 75,
          color: Colors.white,
          child: SizedBox(
            child: RaisedButton(
              onPressed: (){},color: Colors.blue,
              child: Text("Set", style: TextStyle(
                  color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
              ),
            ),
          ),
        ),
      ),

    );
  }
}