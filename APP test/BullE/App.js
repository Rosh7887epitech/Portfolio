import * as React from 'react';
import { NavigationContainer } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import HomeScreen from './HomeScreen';
import DebutScreen from './DebutScreen';
import Compte from './Compte';

const Stack = createNativeStackNavigator();

function App() {
  return (
    <NavigationContainer>
      <Stack.Navigator initialRouteName="Home">
        <Stack.Screen name="Tricount" component={HomeScreen}
        options={{
          title: 'Tricount',
          headerStyle: {
            backgroundColor: '#303030',
          },
          headerTintColor: '#fff',
          headerTitleStyle: {
            fontWeight: 'bold',
          },
        }}
        />
        <Stack.Screen
          name="Debut"
          component={DebutScreen}
          options={{
            title: 'Création du groupe',
            headerStyle: {
              backgroundColor: '#303030',
            },
            headerTintColor: '#fff',
            headerTitleStyle: {
              fontWeight: 'bold',
            },
          }}
        />
        <Stack.Screen name="Comptes" component={Compte}
        options={{
          title: 'Les comptes',
          headerStyle: {
            backgroundColor: '#303030',
          },
          headerTintColor: '#fff',
          headerTitleStyle: {
            fontWeight: 'bold',
          },
        }}
        />
      </Stack.Navigator>
    </NavigationContainer>
  );
}


export default App;
