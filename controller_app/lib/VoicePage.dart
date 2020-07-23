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
              child: Container(
                child: LayoutBuilder(
                  builder: (_, constraints){
                    return Row(
                      children: <Widget>[
                        SizedBox(width: constraints.maxWidth* .03,),
                        Container(
                          child: Column(
                            children: <Widget>[
                              Container(
                                height: constraints.maxHeight* .1,
                                width: constraints.maxWidth* .22,
                                color: Colors.blue,
                                child: SizedBox(
                                  child: RaisedButton(onPressed: (){},color: Colors.deepOrange,
                                    child: Text("Group 1", style: TextStyle(
                                        color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                                    ),
                                  ),

                                ),
                              ),
                              SizedBox(height: 20,),
                              Container(
                                height: constraints.maxHeight* .1,
                                width: constraints.maxWidth* .22,
                                color: Colors.blue,
                                child: SizedBox(
                                  child: RaisedButton(onPressed: (){},color: Colors.blue,
                                    child: Text("Place 1", style: TextStyle(
                                        color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                                    ),
                                  ),
                                ),
                              ),
                              SizedBox(height: 20,),
                              Container(
                                height: constraints.maxHeight* .1,
                                width: constraints.maxWidth* .22,
                                color: Colors.blue,
                                child: SizedBox(
                                  child: RaisedButton(onPressed: (){},color: Colors.blue,
                                    child: Text("Place 2", style: TextStyle(
                                        color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                                    ),
                                  ),
                                ),
                              ),
                              SizedBox(height: 20,),
                              Container(height: constraints.maxHeight* .1,
                                width: constraints.maxWidth* .22,
                                color: Colors.blue,
                                child: SizedBox(
                                  child: RaisedButton(onPressed: (){},color: Colors.blue,
                                    child: Text("Place 3", style: TextStyle(
                                        color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                                    ),
                                  ),
                                ),
                              ),
                              SizedBox(height: 20,),
                              Container(
                                height: constraints.maxHeight* .1,
                                width: constraints.maxWidth* .22,
                                color: Colors.blue,
                                child: SizedBox(
                                  child: RaisedButton(onPressed: (){},color: Colors.blue,
                                    child: Text("Place 4", style: TextStyle(
                                        color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                                    ),
                                  ),
                                ),
                              ),
                            ],
                          ),
                        ),
                        SizedBox(width: constraints.maxWidth* .02,),
                        Container(
                          child: Column(
                            children: <Widget>[
                              Container(
                                height: constraints.maxHeight* .1,
                                width: constraints.maxWidth* .22,
                                color: Colors.blue,
                                child: SizedBox(
                                  child: RaisedButton(onPressed: (){},color: Colors.deepOrange,
                                    child: Text("Group 2", style: TextStyle(
                                        color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                                    ),
                                  ),
                                ),
                              ),
                              SizedBox(height: 20,),
                              Container(
                                height: constraints.maxHeight* .1,
                                width: constraints.maxWidth* .22,
                                color: Colors.blue,
                                child: SizedBox(
                                  child: RaisedButton(onPressed: (){},color: Colors.blue,
                                    child: Text("Place 5", style: TextStyle(
                                        color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                                    ),
                                  ),
                                ),
                              ),
                              SizedBox(height: 20,),
                              Container(
                                height: constraints.maxHeight* .1,
                                width: constraints.maxWidth* .22,
                                color: Colors.blue,
                                child: SizedBox(
                                  child: RaisedButton(onPressed: (){},color: Colors.blue,
                                    child: Text("Place 6", style: TextStyle(
                                        color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                                    ),
                                  ),
                                ),
                              ),
                              SizedBox(height: 20,),
                              Container(height: constraints.maxHeight* .1,
                                width: constraints.maxWidth* .22,
                                color: Colors.blue,
                                child: SizedBox(
                                  child: RaisedButton(onPressed: (){},color: Colors.blue,
                                    child: Text("Place 7", style: TextStyle(
                                        color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                                    ),
                                  ),
                                ),
                              ),
                              SizedBox(height: 20,),
                              Container(
                                height: constraints.maxHeight* .1,
                                width: constraints.maxWidth* .22,
                                color: Colors.blue,
                                child: SizedBox(
                                  child: RaisedButton(onPressed: (){},color: Colors.blue,
                                    child: Text("Place 8", style: TextStyle(
                                        color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                                    ),
                                  ),
                                ),
                              ),
                            ],
                          ),
                        ),
                        SizedBox(width: constraints.maxWidth* .02,),
                        Container(
                          child: Column(
                            children: <Widget>[
                              Container(
                                height: constraints.maxHeight* .1,
                                width: constraints.maxWidth* .22,
                                color: Colors.blue,
                                child: SizedBox(
                                  child: RaisedButton(onPressed: (){},color: Colors.deepOrange,
                                    child: Text("Group 3", style: TextStyle(
                                        color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                                    ),
                                  ),
                                ),
                              ),
                              SizedBox(height: 20,),
                              Container(
                                height: constraints.maxHeight* .1,
                                width: constraints.maxWidth* .22,
                                color: Colors.blue,
                                child: SizedBox(
                                  child: RaisedButton(onPressed: (){},color: Colors.blue,
                                    child: Text("Place 9", style: TextStyle(
                                        color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                                    ),
                                  ),
                                ),
                              ),
                              SizedBox(height: 20,),
                              Container(
                                height: constraints.maxHeight* .1,
                                width: constraints.maxWidth* .22,
                                color: Colors.blue,
                                child: SizedBox(
                                  child: RaisedButton(onPressed: (){},color: Colors.blue,
                                    child: Text("Place 10", style: TextStyle(
                                        color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                                    ),
                                  ),
                                ),
                              ),
                              SizedBox(height: 20,),
                              Container(height: constraints.maxHeight* .1,
                                width: constraints.maxWidth* .22,
                                color: Colors.blue,
                                child: SizedBox(
                                  child: RaisedButton(onPressed: (){},color: Colors.blue,
                                    child: Text("Place 11", style: TextStyle(
                                        color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                                    ),
                                  ),
                                ),
                              ),
                              SizedBox(height: 20,),
                              Container(
                                height: constraints.maxHeight* .1,
                                width: constraints.maxWidth* .22,
                                color: Colors.blue,
                                child: SizedBox(
                                  child: RaisedButton(onPressed: (){},color: Colors.blue,
                                    child: Text("Place 12", style: TextStyle(
                                        color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                                    ),
                                  ),
                                ),
                              ),
                            ],
                          ),
                        ),
                        SizedBox(width: constraints.maxWidth* .02,),
                        Container(
                          child: Column(
                            children: <Widget>[
                              Container(
                                height: constraints.maxHeight* .1,
                                width: constraints.maxWidth* .22,
                                color: Colors.blue,
                                child: SizedBox(
                                  child: RaisedButton(onPressed: (){},color: Colors.deepOrange,
                                    child: Text("Group 4", style: TextStyle(
                                        color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                                    ),
                                  ),
                                ),
                              ),
                              SizedBox(height: 20,),
                              Container(
                                height: constraints.maxHeight* .1,
                                width: constraints.maxWidth* .22,
                                color: Colors.blue,
                                child: SizedBox(
                                  child: RaisedButton(onPressed: (){},color: Colors.blue,
                                    child: Text("Place 13", style: TextStyle(
                                        color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                                    ),
                                  ),
                                ),
                              ),
                              SizedBox(height: 20,),
                              Container(
                                height: constraints.maxHeight* .1,
                                width: constraints.maxWidth* .22,
                                color: Colors.blue,
                                child: SizedBox(
                                  child: RaisedButton(onPressed: (){},color: Colors.blue,
                                    child: Text("Place 14", style: TextStyle(
                                        color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                                    ),
                                  ),
                                ),
                              ),
                              SizedBox(height: 20,),
                              Container(height: constraints.maxHeight* .1,
                                width: constraints.maxWidth* .22,
                                color: Colors.blue,
                                child: SizedBox(
                                  child: RaisedButton(onPressed: (){},color: Colors.blue,
                                    child: Text("Place 15", style: TextStyle(
                                        color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                                    ),
                                  ),
                                ),
                              ),
                              SizedBox(height: 20,),
                              Container(
                                height: constraints.maxHeight* .1,
                                width: constraints.maxWidth* .22,
                                color: Colors.blue,
                                child: SizedBox(
                                  child: RaisedButton(onPressed: (){},color: Colors.blue,
                                    child: Text("Place 16", style: TextStyle(
                                        color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                                    ),
                                  ),
                                ),
                              ),
                            ],
                          ),
                        ),
                        SizedBox(width: constraints.maxWidth* .03,),
                      ],
                    );
                  },
                ),
              ),
            ),
          ],
        ),
      ),
    );

  }
}
