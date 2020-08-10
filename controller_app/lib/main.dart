import 'package:controllerapp/pages/ExamplesList.dart';
import 'package:controllerapp/pages/MyPlaces.dart';
import 'package:controllerapp/pages/NetworkInfo.dart';
import 'package:controllerapp/pages/About.dart';
import 'file:///D:/Arduino-Controller/controller_app/lib/widgets/logos.dart';
import 'package:flutter/material.dart';
import 'package:foldable_sidebar/foldable_sidebar.dart';
import 'package:swipedetector/swipedetector.dart';

import 'pages/Connect.dart';
import 'widgets/list.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  final routes = <String, WidgetBuilder>{
    ListPage.tag: (context) => ListPage(),
    MyPlaces.tag:(context) => MyPlaces(),
    NetInfoPage.tag:(context) => NetInfoPage(),
    Exampleslist.tag:(context) => Exampleslist()
  };

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
      routes: routes,
    );
  }
}

String variavel = "{-122.485046,37.820047,3000},{78.042202,27.172969,1500},{-43.210317,-22.951838,400},{-88.567935,20.683510,600},{12.492135,41.890079,600},{-72.545224,-13.163820,600},{35.441919,30.328456,600},{2.294473,48.857730,1000},{-0.124419,51.500769,500},{-74.044535,40.689437,500},{37.623446,55.752362,500},{-73.985359,40.748360,500},{-51.049260,0.030478,500},{31.132695,29.976603,500},{0.626502,41.617540,600},{116.562771,40.435456,500}";
String valido = "-122.485046-,37.820047-,3000,*78.042202-,27.172969-,1500,*-43.210317-,-22.951838-,400,*-88.567935-,20.683510-,600,*12.492135-,41.890079-,600,*-72.545224-,-13.163820-,600,*35.441919-,30.328456-,600,*2.294473-,48.857730-,1000,*-0.124419-,51.500769-,500,*-74.044535-,40.689437-,500,*37.623446-,55.752362-,500,*-73.985359-,40.748360-,500,*-51.049260-,0.030478-,500,*31.132695-,29.976603-,500,*0.626502-,41.617540-,600,*116.562771-,40.435456-,500,";

String netIP = "";
String netSSID = "";
String netPASSWORD ="";

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
                screenContents: FirstScreen(), status: null, drawer: null,
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

    return LogosPage();
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
                            Navigator.of(context).push(MaterialPageRoute(builder: (context)=>MyPlaces()));
                            //Navigator.of(context).pushNamed(KeyBoardPage.tag);
                            closeDrawer();
                          },
                          leading: Icon(Icons.list),
                          title: Text("My Places"),
                        ),
                        Divider(
                          height: 1,
                          color: Colors.grey,
                        ),
                        ListTile(
                          onTap: () {
                            Navigator.of(context).push(MaterialPageRoute(builder: (context)=>Exampleslist()));
                            //Navigator.of(context).pushNamed(ExamplesPage.tag);
                            closeDrawer();
                          },
                          leading: Icon(Icons.add_to_photos),
                          title: Text("Examples"),
                        ),
                        Divider(
                          height: 1,
                          color: Colors.grey,
                        ),
                        ListTile(
                          onTap: () {
                            Navigator.of(context).push(MaterialPageRoute(builder: (context)=>NetInfoPage()));
                            closeDrawer();
                           //debugPrint("Settings");
                          },
                          leading: Icon(Icons.wifi),
                          title: Text("Network Info"),
                        ),
                        Divider(
                          height: 1,
                          color: Colors.grey,
                        ),
                        ListTile(
                          onTap: () {
                            Navigator.of(context).push(MaterialPageRoute(builder: (context)=>Info()));
                            closeDrawer();
                          },
                          leading: Icon(Icons.info_outline),
                          title: Text("About"),
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