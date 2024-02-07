import React, { useState, useEffect } from 'react';
import { StyleSheet, Text, View, TouchableOpacity, Alert, StatusBar, ScrollView } from 'react-native';
import AsyncStorage from '@react-native-async-storage/async-storage';

function HomeScreen({ navigation, route }) {
    const [groups, setGroups] = useState([]);

    useEffect(() => {
        const loadGroups = async () => {
            try {
                const storedGroups = await AsyncStorage.getItem('groups');
                if (storedGroups !== null) {
                    setGroups(JSON.parse(storedGroups));
                }
            } catch (error) {
                Alert.alert('Erreur', 'Impossible de charger les données.');
            }
        };
        loadGroups();
    }, []);

    useEffect(() => {
        if (route.params?.newGroup) {
            const newGroups = [...groups, {...route.params.newGroup, id: Date.now().toString()}]; // Assurez-vous que chaque nouveau groupe a un ID unique
            setGroups(newGroups);
            AsyncStorage.setItem('groups', JSON.stringify(newGroups));
        }
    }, [route.params?.newGroup]);

    const deleteGroup = async (groupId) => {
        const filteredGroups = groups.filter(group => group.id.toString() !== groupId.toString());
        setGroups(filteredGroups);
        await AsyncStorage.setItem('groups', JSON.stringify(filteredGroups));
    };

    const handlePress = () => {
        navigation.navigate('Debut');
    };

    const openGroupDetails = (group) => {
        navigation.navigate('Comptes', { group });
    };

    return (
        <View style={styles.container}>
            <Text style={styles.text}>Vos groupes</Text>
            <ScrollView style={styles.groupsList}>
                {groups.map((group, index) => (
                    <View key={index} style={styles.groupContainer}>
                        <TouchableOpacity onPress={() => openGroupDetails(group)}>
                            <Text style={styles.groupTitle}>{group.title}</Text>
                            <Text style={styles.groupDescription}>{group.description}</Text>
                        </TouchableOpacity>
                        <TouchableOpacity
                            onPress={() => deleteGroup(group.id)}
                            style={styles.deleteButton}>
                            <Text style={styles.deleteButtonText}>X</Text>
                        </TouchableOpacity>
                    </View>
                ))}
            </ScrollView>
            <TouchableOpacity style={styles.button} onPress={handlePress}>
                <Text style={styles.buttonText}>+</Text>
            </TouchableOpacity>
            <StatusBar style="auto" />
        </View>
    );
}

const styles = StyleSheet.create({
    container: {
        flex: 1,
        backgroundColor: '#202020',
    },
    text: {
        color: 'white',
        fontSize: 20,
        position: 'absolute',
        top: 50,
        left: 10,
        fontWeight: 'bold',
    },
    deleteButton: {
        backgroundColor: 'red',
        padding: 5,
        borderRadius: 5,
    },
    deleteButtonText: {
        color: 'white',
        fontSize: 12,
        fontWeight: 'bold',
    },
    groupsList: {
        marginTop: 70,
        width: '100%',
    },
    groupContainer: {
        flexDirection: 'row',
        justifyContent: 'space-between',
        padding: 10,
        borderBottomWidth: 1,
        borderBottomColor: 'grey',
    },
    groupTitle: {
        color: 'white',
        fontSize: 16,
        fontWeight: 'bold',
    },
    groupDescription: {
        color: 'grey',
        fontSize: 14,
    },
    button: {
        position: 'absolute',
        bottom: 20,
        right: 20,
        backgroundColor: '#fff',
        width: 60,
        height: 60,
        borderRadius: 30,
        alignItems: 'center',
        justifyContent: 'center',
        elevation: 8,
        shadowOpacity: 0.3,
        shadowRadius: 4,
        shadowOffset: { height: 2, width: 0 },
    },
    buttonText: {
        color: 'black',
        textAlign: 'center',
        fontSize: 24,
        fontWeight: 'bold',
    },
});

export default HomeScreen;
