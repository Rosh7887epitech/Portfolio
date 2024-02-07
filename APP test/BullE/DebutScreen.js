import React, { useState } from 'react';
import { View, Text, TextInput, TouchableOpacity, StyleSheet, ScrollView } from 'react-native';

function DebutScreen({ navigation }) {
    const [title, setTitle] = useState('');
    const [description, setDescription] = useState('');

    const handleAddGroup = () => {
        const newGroup = { title, description };
        navigation.navigate('Tricount', { newGroup });
    };

    return (
        <ScrollView style={styles.container}>
            <Text style={styles.header}>Nouveau tricount</Text>
            <TextInput
                style={styles.input}
                placeholder="Titre"
                value={title}
                onChangeText={setTitle}
                placeholderTextColor="grey"
            />
            <TextInput
                style={styles.input}
                placeholder="Description"
                value={description}
                onChangeText={setDescription}
                placeholderTextColor="grey"
            />
            <TouchableOpacity style={styles.addButton} onPress={handleAddGroup}>
                <Text style={styles.addButtonText}>Ajouter</Text>
            </TouchableOpacity>
        </ScrollView>
    );
}

const styles = StyleSheet.create({
    container: {
        flex: 1,
        backgroundColor: '#202020',
    },
    header: {
        color: 'white',
        fontSize: 20,
        fontWeight: 'bold',
        marginTop: 10,
        marginLeft: 10,
    },
    input: {
        color: 'white',
        borderBottomColor: 'grey',
        borderBottomWidth: 1,
        margin: 10,
        paddingVertical: 5,
        fontSize: 18,
    },
    addButton: {
        position: 'absolute',
        bottom: 108,
        right: 10,
        backgroundColor: '#e91e63',
        borderRadius: 30,
        paddingVertical: 10,
        paddingHorizontal: 20,
        elevation: 8,
        shadowOpacity: 0.3,
        shadowRadius: 4,
        shadowOffset: { height: 2, width: 0 },
    },
    addButtonText: {
        color: 'white',
        fontSize: 16,
        fontWeight: 'bold',
    },
});

export default DebutScreen;