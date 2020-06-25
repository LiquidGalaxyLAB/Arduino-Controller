import 'package:flutter/material.dart';
import 'package:flutterappbosta/BluetoohPage.dart';
import 'package:flutterappbosta/KeyBoard.dart';
import 'package:flutterappbosta/Ultrasonic.dart';
import 'package:flutterappbosta/VoicePage.dart';
import 'package:foldable_sidebar/foldable_sidebar.dart';
import 'package:swipedetector/swipedetector.dart';


void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Flutter Demo',
      theme: ThemeData(
        primarySwatch: Colors.blue,
        visualDensity: VisualDensity.adaptivePlatformDensity,
      ),
      home: MyHomePage(),
    );
  }
}

class MyHomePage extends StatefulWidget {
  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  FSBStatus drawerStatus;

  @override
  Widget build(BuildContext context) {
    return SafeArea(
      child: Scaffold(
        body:  SwipeDetector(
          onSwipeRight: (){
            setState(() {
              drawerStatus = FSBStatus.FSB_OPEN;
            });
          },
          onSwipeLeft: (){
            setState(() {
             drawerStatus = FSBStatus.FSB_CLOSE;
            });
          },
          child: FoldableSidebarBuilder(
            drawerBackgroundColor: Colors.blue,
            drawer: CustomDrawer(closeDrawer: (){
              setState(() {
                drawerStatus = FSBStatus.FSB_CLOSE;
              });
            },),
            screenContents: Scaffold(
                  appBar: AppBar(
                    title: Text("Arduino LG Controller"),
                    backgroundColor: Colors.blue,
                    leading: IconButton(icon: Icon(Icons.menu,color: Colors.white,size: 35,),
                        onPressed: (){
                      setState(() {
                        drawerStatus = drawerStatus == FSBStatus.FSB_OPEN ? FSBStatus.FSB_CLOSE : FSBStatus.FSB_OPEN;
                      });
                        }),
                  ),
              body: FoldableSidebarBuilder(
                screenContents: FirstScreen(),
              ),
            ),
            status: drawerStatus,
          ),
        ),
      ),
    );
  }
}

class FirstScreen extends StatelessWidget {
    @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        child: Container(
          child: SizedBox(
            child: RaisedButton(
              onPressed: (){

              },
              child: Text("Bluetooth Connect", style: TextStyle(
                  color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
              ),
              color: Colors.blue,
              elevation: 10,
            ),
          ),
          width: 200,
          height: 100,
        ),
      ),
    );
  }
}

class CustomDrawer extends StatelessWidget {

  final Function closeDrawer;

  const CustomDrawer({Key key, this.closeDrawer}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    MediaQueryData mediaQuery = MediaQuery.of(context);
    var size = MediaQuery.of(context).size;
    return Container(
      color: Colors.white,
      width: mediaQuery.size.width * 0.60,
      height: size.height,
      child: Column(
        children: <Widget>[
          Container(
              width: double.infinity,
              height: 200,
              color: Colors.blue.withAlpha(180),
              child: Column(
                mainAxisAlignment: MainAxisAlignment.center,
                children: <Widget>[
                  Image.asset(
                    "assets/lg_logo.png",
                    width: 150,
                    height: 150,
                  ),
                  SizedBox(
                    height: 1,
                  ),
                  Text("Liquid Galaxy",
                    style: TextStyle(color: Colors.white,fontSize: 20,fontWeight: FontWeight.w700),
                  )
                ],
              )),
          Expanded(
            child: Container(
              child: LayoutBuilder(
                builder: (_,constraints){
                  return Container(
                    height: constraints.maxHeight,
                    child: ListView(
                      children: <Widget>[
                        ListTile(
                          onTap: (){
                            Navigator.of(context).push(MaterialPageRoute(builder: (context)=>BluetoothPage()));
                            closeDrawer();
                          },
                          leading: Icon(Icons.bluetooth_connected),
                          title: Text(
                            "Connect",
                          ),
                        ),
                        Divider(
                          height: 1,
                          color: Colors.grey,
                        ),
                        ListTile(
                          onTap: () {
                            Navigator.of(context).push(MaterialPageRoute(builder: (context)=>KeyBoardPage()));
                            closeDrawer();
                          },
                          leading: Icon(Icons.keyboard),
                          title: Text("Keyboard"),
                        ),
                        Divider(
                          height: 1,
                          color: Colors.grey,
                        ),
                        ListTile(
                          onTap: () {
                            Navigator.of(context).push(MaterialPageRoute(builder: (context)=>VoicePage()));
                            closeDrawer();
                          },
                          leading: Icon(Icons.settings_voice),
                          title: Text("Voice Recognition"),
                        ),
                        Divider(
                          height: 1,
                          color: Colors.grey,
                        ),
                        ListTile(
                          onTap: () {
                            Navigator.of(context).push(MaterialPageRoute(builder: (context)=>UltrasonicPage()));
                            closeDrawer();
                          },
                          leading: Icon(Icons.surround_sound),
                          title: Text("Ultrasonic"),
                        ),
                        Divider(
                          height: 1,
                          color: Colors.grey,
                        ),
                        ListTile(
                          onTap: () {
                            debugPrint("Accelerometer");
                          },
                          leading: Icon(Icons.vertical_align_center),
                          title: Text("Accelerometer"),
                        ),
                        Divider(
                          height: 1,
                          color: Colors.grey,
                        ),
                        ListTile(
                          onTap: () {
                            debugPrint("Settings");
                          },
                          leading: Icon(Icons.settings),
                          title: Text("Settings"),
                        ),



                      ],
                    ),
                  );
                },
              ),
            ),
          ),


        ],
      ),
    );
  }
}