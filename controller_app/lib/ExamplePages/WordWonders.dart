import 'package:flutter/material.dart';

final List<String> _wordWonders= <String>['{-122.485046,37.820047,3000}','{78.042202,27.172969,1500}','{-43.210317,-22.951838,400}','{-88.567935,20.683510,600}','{12.492135,41.890079,600}','{-72.545224,-13.163820,600}','{35.441919,30.328456,600}','{2.294473,48.857730,1000}','{-0.124419,51.500769,500}','{-74.044535,40.689437,500}','{37.623446,55.752362,500}','{-73.985359,40.748360,500}','{-51.049260,0.030478,500}','{31.132695,29.976603,500}','{0.626502,41.617540,600}','{116.562771,40.435456,500}'];


class WordWondersPage extends StatelessWidget {
  static final tag = 'wordwonders-page';
  @override
  Widget build(BuildContext context) {
    return SingleChildScrollView(
      child: Container(height: 2000,color: Colors.red),
    );
  }
}