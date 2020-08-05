import 'package:controllerapp/ExamplePages/Football.dart';
import 'package:controllerapp/ExamplePages/RaccingCircuit.dart';
import 'package:controllerapp/ExamplePages/WordWonders.dart';
import 'package:flutter/material.dart';

String dropdownValue = '';
var _Continents = ['America','Africa','Europe','Oceania','Asia'];
var select = '';

class ExamplesPage extends StatelessWidget {
  static final tag = 'examples-page';
  static final ExamplePages = [
    FootballPage(),
    RaccingPage(),
    WordWondersPage()
  ];

  static var pageControl = ExamplePages[0];

  @override
  Widget build(BuildContext context) {
    var appBar = AppBar(title: Text("Navigation Examples"));
    var size = MediaQuery.of(context).size;

    return Scaffold(
      appBar: appBar,
      body: Container(
        width: size.width,
        height: size.height,
        color: Colors.white,
        child: Column(
          children: <Widget>[
            SizedBox(height: 10),
            Row(
              children: <Widget>[
                Container(width: size.width*.025),
                Container(
                  width: size.width*.3,
                  height: size.height*.07,
                  child: SizedBox(
                    child: RaisedButton(
                      onPressed: (){
                        pageControl = ExamplePages[0];
                        Navigator.of(context).pushReplacementNamed(ExamplesPage.tag);
                      },
                      child: Row(
                        children: <Widget>[
                          //SizedBox(width: 5),
                          Text("Football \nStadiums", style: TextStyle(
                              color: Colors.white,fontSize: 15,fontWeight: FontWeight.w700),
                          ),
                        ],
                      ),
                      color: Colors.green,
                      elevation: 10,
                    ),
                  ),
                ),
                Container(width: size.width*.025),
                Container(
                  width: size.width*.3,
                  height: size.height*.07,
                  child: SizedBox(
                    child: RaisedButton(
                      onPressed: (){
                        pageControl = ExamplePages[1];
                        Navigator.of(context).pushReplacementNamed(ExamplesPage.tag);
                      },
                      child: Row(
                        children: <Widget>[
                          //SizedBox(width: 5),
                          Text("Racing \nCircuits", style: TextStyle(
                              color: Colors.white,fontSize: 15,fontWeight: FontWeight.w700),
                          ),
                        ],
                      ),
                      color: Colors.blue,
                      elevation: 10,
                    ),
                  ),
                ),
                Container(width: size.width*.025),
                Container(
                  width: size.width*.3,
                  height: size.height*.07,
                  child: SizedBox(
                    child: RaisedButton(
                      onPressed: (){
                        pageControl = ExamplePages[2];
                        select = '';
                        Navigator.of(context).pushReplacementNamed(ExamplesPage.tag);
                      },
                      child: Row(
                        children: <Widget>[
                          //SizedBox(width: 5),
                          Text("Word \nWonders", style: TextStyle(
                              color: Colors.white,fontSize: 15,fontWeight: FontWeight.w700),
                          ),
                        ],
                      ),
                      color: Colors.red,
                      elevation: 10,
                    ),
                  ),
                ),
              ],
            ),
            Container(height: 10),
            Container(
              width: size.width,
              height: size.height*.07,
              child: Padding(
                padding: const EdgeInsets.all(1),
                child: Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: <Widget>[
                    Container(),
                    Text('Select a Continent', style: TextStyle(
                        color: Colors.black,fontSize: 18),
                    ),
                     DropdownButton<String>(
                       hint: Text(select, style: TextStyle(
                           color: Colors.black,fontSize: 20),
                       ),
                      items: _Continents.map((String value) {
                        return DropdownMenuItem<String>(
                          value: value,
                          child: Text(value, style: TextStyle(
                              color: Colors.black,fontSize: 18),
                          ),
                        );
                      }).toList(),
                      onChanged: (String value) {
                        select = value;
                        Navigator.of(context).pushReplacementNamed(ExamplesPage.tag);
                      },
                    ),
                    Container()
                  ],
                ),
              )
            ),
            Container(height: 10),
            Expanded(
              child: Container(
                width: size.width*.96,
                height: size.height*.5,
                color: Colors.white,
                child: LayoutBuilder(
                  builder: (_,constraints){
                    return pageControl;
                  }
              ),
            ),
            ),
          ],
        ),
      ),
    );

  }
}
